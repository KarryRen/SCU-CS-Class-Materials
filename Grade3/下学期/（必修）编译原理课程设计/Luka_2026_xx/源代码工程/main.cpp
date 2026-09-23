#include <cctype>
#include <fstream>
#include <iostream>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

static const string STUDENT_INFO = "2023141460228 Xu Tao";

enum class TokenType {
    End,
    If,
    Else,
    Int,
    Return,
    Void,
    While,
    Id,
    Num,
    Plus,
    Minus,
    Times,
    Over,
    Lt,
    Le,
    Gt,
    Ge,
    Eq,
    Ne,
    Assign,
    Semi,
    Comma,
    LParen,
    RParen,
    LBracket,
    RBracket,
    LBrace,
    RBrace
};

struct Token {
    TokenType type;
    string lexeme;
    int lineNo;
};

struct TreeNode {
    string label;
    vector<unique_ptr<TreeNode>> children;

    explicit TreeNode(const string &text) : label(text) {}
};

static unique_ptr<TreeNode> makeNode(const string &label) {
    return unique_ptr<TreeNode>(new TreeNode(label));
}

static void addChild(TreeNode *parent, unique_ptr<TreeNode> child) {
    if (parent && child) {
        parent->children.push_back(move(child));
    }
}

static bool isKeyword(const string &word, TokenType &type) {
    if (word == "if") {
        type = TokenType::If;
    } else if (word == "else") {
        type = TokenType::Else;
    } else if (word == "int") {
        type = TokenType::Int;
    } else if (word == "return") {
        type = TokenType::Return;
    } else if (word == "void") {
        type = TokenType::Void;
    } else if (word == "while") {
        type = TokenType::While;
    } else {
        return false;
    }
    return true;
}

static string outputNameFromInput(const string &inputName) {
    size_t slash = inputName.find_last_of("\\/");
    string dir = (slash == string::npos) ? "" : inputName.substr(0, slash + 1);
    string name = (slash == string::npos) ? inputName : inputName.substr(slash + 1);
    size_t dot = name.find_last_of('.');
    if (dot != string::npos) {
        name = name.substr(0, dot);
    }
    return dir + name + ".txt";
}

static string tokenName(TokenType type) {
    switch (type) {
    case TokenType::End: return "EOF";
    case TokenType::If: return "if";
    case TokenType::Else: return "else";
    case TokenType::Int: return "int";
    case TokenType::Return: return "return";
    case TokenType::Void: return "void";
    case TokenType::While: return "while";
    case TokenType::Id: return "ID";
    case TokenType::Num: return "NUM";
    case TokenType::Plus: return "+";
    case TokenType::Minus: return "-";
    case TokenType::Times: return "*";
    case TokenType::Over: return "/";
    case TokenType::Lt: return "<";
    case TokenType::Le: return "<=";
    case TokenType::Gt: return ">";
    case TokenType::Ge: return ">=";
    case TokenType::Eq: return "==";
    case TokenType::Ne: return "~=";
    case TokenType::Assign: return "=";
    case TokenType::Semi: return ";";
    case TokenType::Comma: return ",";
    case TokenType::LParen: return "(";
    case TokenType::RParen: return ")";
    case TokenType::LBracket: return "[";
    case TokenType::RBracket: return "]";
    case TokenType::LBrace: return "{";
    case TokenType::RBrace: return "}";
    }
    return "unknown";
}

static void addError(vector<string> &errors, int lineNo, const string &message) {
    ostringstream out;
    out << "\t" << lineNo << ": ERROR: " << message << " " << STUDENT_INFO;
    errors.push_back(out.str());
}

static vector<Token> scanFile(const string &fileName, vector<string> &errors) {
    ifstream in(fileName.c_str());
    vector<Token> tokens;
    string line;
    int lineNo = 1;

    enum class DfaState {
        START,
        IN_ID,
        IN_NUM,
        IN_DIV,
        IN_LT,
        IN_GT,
        IN_EQ,
        IN_TILDE,
        IN_COMMENT,
        IN_COMMENT_STAR
    };
    DfaState state = DfaState::START;
    string buf;

    while (getline(in, line)) {
        size_t i = 0;

        while (i < line.size() || state == DfaState::IN_COMMENT || state == DfaState::IN_COMMENT_STAR) {
            if (i >= line.size()) {
                if (state == DfaState::IN_COMMENT || state == DfaState::IN_COMMENT_STAR) {
                    break;
                }
            }

            unsigned char ch = (i < line.size()) ? static_cast<unsigned char>(line[i]) : '\0';

            switch (state) {
                case DfaState::START:
                    switch (ch) {
                        case ' ':
                        case '\t':
                        case '\r':
                            ++i;
                            break;
                        case '/':
                            state = DfaState::IN_DIV;
                            ++i;
                            break;
                        case '<':
                            state = DfaState::IN_LT;
                            ++i;
                            break;
                        case '>':
                            state = DfaState::IN_GT;
                            ++i;
                            break;
                        case '=':
                            state = DfaState::IN_EQ;
                            ++i;
                            break;
                        case '~':
                            state = DfaState::IN_TILDE;
                            ++i;
                            break;
                        default:
                            if (isalpha(ch)) {
                                buf = string(1, line[i]);
                                state = DfaState::IN_ID;
                                ++i;
                            } else if (isdigit(ch)) {
                                buf = string(1, line[i]);
                                state = DfaState::IN_NUM;
                                ++i;
                            } else {
                                switch (line[i]) {
                                    case '+': tokens.push_back({TokenType::Plus, "+", lineNo}); break;
                                    case '-': tokens.push_back({TokenType::Minus, "-", lineNo}); break;
                                    case '*': tokens.push_back({TokenType::Times, "*", lineNo}); break;
                                    case ';': tokens.push_back({TokenType::Semi, ";", lineNo}); break;
                                    case ',': tokens.push_back({TokenType::Comma, ",", lineNo}); break;
                                    case '(': tokens.push_back({TokenType::LParen, "(", lineNo}); break;
                                    case ')': tokens.push_back({TokenType::RParen, ")", lineNo}); break;
                                    case '[': tokens.push_back({TokenType::LBracket, "[", lineNo}); break;
                                    case ']': tokens.push_back({TokenType::RBracket, "]", lineNo}); break;
                                    case '{': tokens.push_back({TokenType::LBrace, "{", lineNo}); break;
                                    case '}': tokens.push_back({TokenType::RBrace, "}", lineNo}); break;
                                    default: addError(errors, lineNo, "invalid token: " + string(1, line[i])); break;
                                }
                                ++i;
                            }
                    }
                    break;

                case DfaState::IN_ID:
                    switch (ch) {
                        default:
                            if (isalpha(ch)) {
                                buf += line[i];
                                ++i;
                            } else {
                                TokenType t = TokenType::Id;
                                isKeyword(buf, t);
                                tokens.push_back({t, buf, lineNo});
                                buf.clear();
                                state = DfaState::START;
                            }
                    }
                    break;

                case DfaState::IN_NUM:
                    switch (ch) {
                        default:
                            if (isdigit(ch)) {
                                buf += line[i];
                                ++i;
                            } else {
                                tokens.push_back({TokenType::Num, buf, lineNo});
                                buf.clear();
                                state = DfaState::START;
                            }
                    }
                    break;

                case DfaState::IN_DIV:
                    switch (ch) {
                        case '*':
                            state = DfaState::IN_COMMENT;
                            ++i;
                            break;
                        default:
                            tokens.push_back({TokenType::Over, "/", lineNo});
                            state = DfaState::START;
                            break;
                    }
                    break;

                case DfaState::IN_LT:
                    switch (ch) {
                        case '=':
                            tokens.push_back({TokenType::Le, "<=", lineNo});
                            ++i;
                            state = DfaState::START;
                            break;
                        default:
                            tokens.push_back({TokenType::Lt, "<", lineNo});
                            state = DfaState::START;
                            break;
                    }
                    break;

                case DfaState::IN_GT:
                    switch (ch) {
                        case '=':
                            tokens.push_back({TokenType::Ge, ">=", lineNo});
                            ++i;
                            state = DfaState::START;
                            break;
                        default:
                            tokens.push_back({TokenType::Gt, ">", lineNo});
                            state = DfaState::START;
                            break;
                    }
                    break;

                case DfaState::IN_EQ:
                    switch (ch) {
                        case '=':
                            tokens.push_back({TokenType::Eq, "==", lineNo});
                            ++i;
                            state = DfaState::START;
                            break;
                        default:
                            tokens.push_back({TokenType::Assign, "=", lineNo});
                            state = DfaState::START;
                            break;
                    }
                    break;

                case DfaState::IN_TILDE:
                    switch (ch) {
                        case '=':
                            tokens.push_back({TokenType::Ne, "~=", lineNo});
                            ++i;
                            state = DfaState::START;
                            break;
                        default:
                            addError(errors, lineNo, "invalid token: ~");
                            state = DfaState::START;
                            break;
                    }
                    break;

                case DfaState::IN_COMMENT:
                    switch (ch) {
                        case '*':
                            state = DfaState::IN_COMMENT_STAR;
                            break;
                        default:
                            break;
                    }
                    ++i;
                    break;

                case DfaState::IN_COMMENT_STAR:
                    switch (ch) {
                        case '/':
                            state = DfaState::START;
                            break;
                        case '*':
                            break;
                        default:
                            state = DfaState::IN_COMMENT;
                            break;
                    }
                    ++i;
                    break;
            }
        }

        switch (state) {
            case DfaState::IN_ID: {
                TokenType t = TokenType::Id;
                isKeyword(buf, t);
                tokens.push_back({t, buf, lineNo});
                buf.clear();
                state = DfaState::START;
                break;
            }
            case DfaState::IN_NUM:
                tokens.push_back({TokenType::Num, buf, lineNo});
                buf.clear();
                state = DfaState::START;
                break;
            case DfaState::IN_DIV:
                tokens.push_back({TokenType::Over, "/", lineNo});
                state = DfaState::START;
                break;
            case DfaState::IN_LT:
                tokens.push_back({TokenType::Lt, "<", lineNo});
                state = DfaState::START;
                break;
            case DfaState::IN_GT:
                tokens.push_back({TokenType::Gt, ">", lineNo});
                state = DfaState::START;
                break;
            case DfaState::IN_EQ:
                tokens.push_back({TokenType::Assign, "=", lineNo});
                state = DfaState::START;
                break;
            case DfaState::IN_TILDE:
                addError(errors, lineNo, "invalid token: ~");
                state = DfaState::START;
                break;
            default:
                break;
        }

        ++lineNo;
    }

    if (state == DfaState::IN_COMMENT || state == DfaState::IN_COMMENT_STAR) {
        addError(errors, lineNo - 1, "unclosed comment");
    }
    tokens.push_back({TokenType::End, "EOF", lineNo});
    return tokens;
}

class Parser {
public:
    explicit Parser(const vector<Token> &input) : tokens(input), current(0) {}

    unique_ptr<TreeNode> parse() {
        unique_ptr<TreeNode> root = makeNode("ProgramK");
        while (!check(TokenType::End)) {
            if (!isTypeSpecifier(peek().type)) {
                syntaxError("expected declaration");
                advance();
                continue;
            }
            addChild(root.get(), declaration());
        }
        return root;
    }

    const vector<string> &getErrors() const {
        return errors;
    }

private:
    const vector<Token> &tokens;
    size_t current;
    vector<string> errors;

    const Token &peek() const {
        return tokens[current];
    }

    const Token &previous() const {
        return tokens[current - 1];
    }

    bool check(TokenType type) const {
        return peek().type == type;
    }

    bool checkNext(TokenType type) const {
        return current + 1 < tokens.size() && tokens[current + 1].type == type;
    }

    bool isAtEnd() const {
        return check(TokenType::End);
    }

    const Token &advance() {
        if (!isAtEnd()) {
            ++current;
        }
        return previous();
    }

    bool match(TokenType type) {
        if (!check(type)) {
            return false;
        }
        advance();
        return true;
    }

    bool consume(TokenType type, const string &message) {
        if (check(type)) {
            advance();
            return true;
        }
        syntaxError(message + ", got " + tokenName(peek().type));
        return false;
    }

    void syntaxError(const string &message) {
        addError(errors, peek().lineNo, message);
    }

    bool isTypeSpecifier(TokenType type) const {
        return type == TokenType::Int || type == TokenType::Void;
    }

    bool isRelop(TokenType type) const {
        return type == TokenType::Lt || type == TokenType::Le || type == TokenType::Gt ||
               type == TokenType::Ge || type == TokenType::Eq || type == TokenType::Ne;
    }

    bool isAddop(TokenType type) const {
        return type == TokenType::Plus || type == TokenType::Minus;
    }

    bool isMulop(TokenType type) const {
        return type == TokenType::Times || type == TokenType::Over;
    }

    unique_ptr<TreeNode> typeSpecifier() {
        if (match(TokenType::Int)) {
            return makeNode("IntK");
        }
        if (match(TokenType::Void)) {
            return makeNode("VoidK");
        }
        syntaxError("expected type specifier");
        return makeNode("ErrorK");
    }

    unique_ptr<TreeNode> idNode(const string &name) {
        return makeNode("IdK: " + name);
    }

    unique_ptr<TreeNode> declaration() {
        unique_ptr<TreeNode> type = typeSpecifier();
        string name = "<missing>";
        if (consume(TokenType::Id, "expected identifier")) {
            name = previous().lexeme;
        }

        if (match(TokenType::LParen)) {
            unique_ptr<TreeNode> node = makeNode("FuncK");
            addChild(node.get(), move(type));
            addChild(node.get(), idNode(name));
            addChild(node.get(), params());
            consume(TokenType::RParen, "expected ')' after parameters");
            addChild(node.get(), compoundStmt());
            return node;
        }

        unique_ptr<TreeNode> node = makeNode("Var_DeclK");
        addChild(node.get(), move(type));
        addChild(node.get(), idNode(name));
        if (match(TokenType::LBracket)) {
            if (consume(TokenType::Num, "expected array size")) {
                addChild(node.get(), makeNode("ConstK: " + previous().lexeme));
            }
            consume(TokenType::RBracket, "expected ']' after array size");
        }
        consume(TokenType::Semi, "expected ';' after variable declaration");
        return node;
    }

    unique_ptr<TreeNode> params() {
        unique_ptr<TreeNode> node = makeNode("ParamsK");
        if (check(TokenType::Void) && checkNext(TokenType::RParen)) {
            advance();
            addChild(node.get(), makeNode("VoidK"));
            return node;
        }
        addChild(node.get(), param());
        while (match(TokenType::Comma)) {
            addChild(node.get(), param());
        }
        return node;
    }

    unique_ptr<TreeNode> param() {
        unique_ptr<TreeNode> node = makeNode("ParamK");
        addChild(node.get(), typeSpecifier());
        string name = "<missing>";
        if (consume(TokenType::Id, "expected parameter name")) {
            name = previous().lexeme;
        }
        addChild(node.get(), idNode(name));
        if (match(TokenType::LBracket)) {
            consume(TokenType::RBracket, "expected ']' after parameter '['");
            addChild(node.get(), makeNode("ArrayParamK"));
        }
        return node;
    }

    unique_ptr<TreeNode> compoundStmt() {
        unique_ptr<TreeNode> node = makeNode("CompK");
        consume(TokenType::LBrace, "expected '{' before compound statement");

        while (isTypeSpecifier(peek().type)) {
            addChild(node.get(), varDeclaration());
        }

        while (!check(TokenType::RBrace) && !check(TokenType::End)) {
            addChild(node.get(), statement());
        }

        consume(TokenType::RBrace, "expected '}' after compound statement");
        return node;
    }

    unique_ptr<TreeNode> varDeclaration() {
        unique_ptr<TreeNode> type = typeSpecifier();
        string name = "<missing>";
        if (consume(TokenType::Id, "expected variable name")) {
            name = previous().lexeme;
        }
        unique_ptr<TreeNode> node = makeNode("Var_DeclK");
        addChild(node.get(), move(type));
        addChild(node.get(), idNode(name));
        if (match(TokenType::LBracket)) {
            if (consume(TokenType::Num, "expected array size")) {
                addChild(node.get(), makeNode("ConstK: " + previous().lexeme));
            }
            consume(TokenType::RBracket, "expected ']' after array size");
        }
        consume(TokenType::Semi, "expected ';' after variable declaration");
        return node;
    }

    unique_ptr<TreeNode> statement() {
        if (check(TokenType::LBrace)) return compoundStmt();
        if (check(TokenType::If)) return selectionStmt();
        if (check(TokenType::While)) return iterationStmt();
        if (check(TokenType::Return)) return returnStmt();
        return expressionStmt();
    }

    unique_ptr<TreeNode> expressionStmt() {
        if (match(TokenType::Semi)) {
            return makeNode("EmptyStmtK");
        }
        unique_ptr<TreeNode> node = expression();
        consume(TokenType::Semi, "expected ';' after expression");
        return node;
    }

    unique_ptr<TreeNode> selectionStmt() {
        consume(TokenType::If, "expected if");
        unique_ptr<TreeNode> node = makeNode("If");
        consume(TokenType::LParen, "expected '(' after if");
        addChild(node.get(), expression());
        consume(TokenType::RParen, "expected ')' after if condition");
        addChild(node.get(), statement());
        if (match(TokenType::Else)) {
            addChild(node.get(), statement());
        }
        return node;
    }

    unique_ptr<TreeNode> iterationStmt() {
        consume(TokenType::While, "expected while");
        unique_ptr<TreeNode> node = makeNode("While");
        consume(TokenType::LParen, "expected '(' after while");
        addChild(node.get(), expression());
        consume(TokenType::RParen, "expected ')' after while condition");
        addChild(node.get(), statement());
        return node;
    }

    unique_ptr<TreeNode> returnStmt() {
        consume(TokenType::Return, "expected return");
        unique_ptr<TreeNode> node = makeNode("Return");
        if (!check(TokenType::Semi)) {
            addChild(node.get(), expression());
        }
        consume(TokenType::Semi, "expected ';' after return statement");
        return node;
    }

    unique_ptr<TreeNode> expression() {
        return assignment();
    }

    unique_ptr<TreeNode> assignment() {
        unique_ptr<TreeNode> left = simpleExpression();
        if (match(TokenType::Assign)) {
            unique_ptr<TreeNode> node = makeNode("Assign");
            addChild(node.get(), move(left));
            addChild(node.get(), assignment());
            return node;
        }
        return left;
    }

    unique_ptr<TreeNode> simpleExpression() {
        unique_ptr<TreeNode> left = additiveExpression();
        if (isRelop(peek().type)) {
            string op = advance().lexeme;
            unique_ptr<TreeNode> node = makeNode("Op: " + op);
            addChild(node.get(), move(left));
            addChild(node.get(), additiveExpression());
            return node;
        }
        return left;
    }

    unique_ptr<TreeNode> additiveExpression() {
        unique_ptr<TreeNode> node = term();
        while (isAddop(peek().type)) {
            string op = advance().lexeme;
            unique_ptr<TreeNode> parent = makeNode("Op: " + op);
            addChild(parent.get(), move(node));
            addChild(parent.get(), term());
            node = move(parent);
        }
        return node;
    }

    unique_ptr<TreeNode> term() {
        unique_ptr<TreeNode> node = factor();
        while (isMulop(peek().type)) {
            string op = advance().lexeme;
            unique_ptr<TreeNode> parent = makeNode("Op: " + op);
            addChild(parent.get(), move(node));
            addChild(parent.get(), factor());
            node = move(parent);
        }
        return node;
    }

    unique_ptr<TreeNode> factor() {
        if (match(TokenType::LParen)) {
            unique_ptr<TreeNode> node = expression();
            consume(TokenType::RParen, "expected ')' after expression");
            return node;
        }

        if (match(TokenType::Num)) {
            return makeNode("ConstK: " + previous().lexeme);
        }

        if (match(TokenType::Id)) {
            string name = previous().lexeme;
            if (match(TokenType::LParen)) {
                unique_ptr<TreeNode> node = makeNode("CallK");
                addChild(node.get(), idNode(name));
                addChild(node.get(), args());
                consume(TokenType::RParen, "expected ')' after arguments");
                return node;
            }
            if (match(TokenType::LBracket)) {
                unique_ptr<TreeNode> node = makeNode("ArrayK");
                addChild(node.get(), idNode(name));
                addChild(node.get(), expression());
                consume(TokenType::RBracket, "expected ']' after array index");
                return node;
            }
            return idNode(name);
        }

        syntaxError("expected expression factor");
        if (!isAtEnd()) {
            advance();
        }
        return makeNode("ErrorK");
    }

    unique_ptr<TreeNode> args() {
        unique_ptr<TreeNode> node = makeNode("ArgsK");
        if (check(TokenType::RParen)) {
            return node;
        }
        addChild(node.get(), expression());
        while (match(TokenType::Comma)) {
            addChild(node.get(), expression());
        }
        return node;
    }
};

static void printTree(ostream &out, const TreeNode *node, int indent = 0) {
    if (!node) {
        return;
    }
    for (int i = 0; i < indent; ++i) {
        out << "  ";
    }
    out << node->label << '\n';
    for (size_t i = 0; i < node->children.size(); ++i) {
        printTree(out, node->children[i].get(), indent + 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: cparser.exe source.c-" << endl;
        return 1;
    }

    ifstream test(argv[1]);
    if (!test) {
        cerr << "Cannot open input file: " << argv[1] << endl;
        return 1;
    }
    test.close();

    vector<string> lexicalErrors;
    vector<Token> tokens = scanFile(argv[1], lexicalErrors);
    Parser parser(tokens);
    unique_ptr<TreeNode> syntaxTree = parser.parse();

    ofstream out(outputNameFromInput(argv[1]).c_str());
    if (!out) {
        cerr << "Cannot create output file." << endl;
        return 1;
    }

    out << "CMINUS PARSING:\n";
    if (!lexicalErrors.empty() || !parser.getErrors().empty()) {
        out << "Errors:\n";
        for (size_t i = 0; i < lexicalErrors.size(); ++i) {
            out << lexicalErrors[i] << '\n';
        }
        const vector<string> &syntaxErrors = parser.getErrors();
        for (size_t i = 0; i < syntaxErrors.size(); ++i) {
            out << syntaxErrors[i] << '\n';
        }
        out << '\n';
    }

    out << "Syntax tree:\n";
    printTree(out, syntaxTree.get());
    return 0;
}

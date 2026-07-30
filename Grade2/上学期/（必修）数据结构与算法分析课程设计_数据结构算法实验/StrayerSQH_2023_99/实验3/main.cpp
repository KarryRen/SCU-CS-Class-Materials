#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <map>
#include <iomanip>
#include <math.h>

using namespace std;

class TreeNode {
private:
    int weight;
    char character;
    TreeNode* parent = NULL;
    TreeNode* leftChild = NULL;
    TreeNode* rightChild = NULL;

public:
    TreeNode(int w, char c = '\0') : weight(w), character(c){}

    int getWeight() 
    {
        return weight;
    }

    char getCharacter() 
    {
        return character;
    }

    TreeNode* GetLeftChild() 
    {
        return leftChild;
    }

    TreeNode* GetRightChild() 
    {
        return rightChild;
    }

    void SetLeftChild(TreeNode* node) 
    {
        leftChild = node;
    }

    void SetRightChild(TreeNode* node) 
    {
        rightChild = node;
    }
};

struct Compare 
{
    bool operator()(TreeNode* l, TreeNode* r) 
    {
        return l->getWeight() > r->getWeight();
    }
};

void GenerateCodes(TreeNode* node, string str, map<char, string>& codes) 
{
    if (node == nullptr)
    {
        return;
    }

    if (node->getCharacter() != '\0') 
    {
        codes[node->getCharacter()] = str;
    }

    GenerateCodes(node->GetLeftChild(), str + "0", codes);
    GenerateCodes(node->GetRightChild(), str + "1", codes);
}

string DecodeCodes(TreeNode* root, string encodedTxt)
{
    TreeNode* current = root;
    string output;
    for (int i = 0; i < encodedTxt.length(); i++)
    {
        if (encodedTxt[i] == '0')
        {
            root->GetLeftChild();
            current = current->GetLeftChild();
        }
        else
        {
            root->GetRightChild();
            current = current->GetRightChild();
        }
        if (current->GetLeftChild() == NULL && current->GetRightChild() == NULL)
        {
            output += current->getCharacter();
            current = root;
        }
    }

    return output;
}

int EncodeFile()
{
    string filename, txt;
    cout << "输入需要压缩的文件名: ";
    cin >> filename;

    ifstream file(filename);

    if (file.is_open())
    {
        stringstream buffer;
        buffer << file.rdbuf();
        txt = buffer.str();
        file.close();
    }
    else
    {
        cout << "无法打开该文件！ " << filename << endl;
        return 1;
    }
    cout << "原文件中的文本为：" << endl;
    cout << txt << endl;
    int arr[256] = { 0 };

    for (int i = 0; i < txt.length(); i++)
    {
        arr[static_cast<int>(txt[i])]++;
    }

    priority_queue<TreeNode*, vector<TreeNode*>, Compare> pq;

    for (int i = 0; i < 256; i++)
    {
        if (arr[i] > 0)
        {
            pq.push(new TreeNode(arr[i], static_cast<char>(i)));
        }
    }

    while (pq.size() != 1)
    {
        TreeNode* left = pq.top();
        pq.pop();
        TreeNode* right = pq.top();
        pq.pop();
        TreeNode* sum = new TreeNode(left->getWeight() + right->getWeight());
        sum->SetLeftChild(left);
        sum->SetRightChild(right);
        pq.push(sum);
    }

    TreeNode* root = pq.top();

    map<char, string> codes;
    GenerateCodes(root, "", codes);

    cout << "各个字符对应的编码为：" << endl;
    string huffmanCode[256];
    for (auto& code : codes)
    {
        huffmanCode[static_cast<int>(code.first)] = code.second;
        cout << code.first << ": " << code.second << endl;
    }

    string outFileName = "Encoded_" + filename;
    ofstream outFile(outFileName);
    if (!outFile.is_open())
    {
        return 1;
    }

    cout << "压缩后的编码为：" << endl;
    string encodedBuffer = "";
    for (int i = 0; i < 256; i++)
    {
        if (arr[i] > 0)
        {
            outFile << setw(3) << setfill('0') << static_cast<int>(i) << " " << setw(4) << arr[i] << endl;
        }
    }
    outFile << '|';
    for (int i = 0; i < txt.length(); i++)
    {
        cout << huffmanCode[static_cast<int>(txt[i])];
        outFile << huffmanCode[static_cast<int>(txt[i])];
    }
    cout << endl << filename << "成功压缩到文件" << outFileName << "中！" << endl;
    outFile.close();

    string encodedTxt;
    ifstream encodedFile(outFileName);
    if (encodedFile.is_open())
    {
        stringstream encodedBuffer;
        encodedBuffer << encodedFile.rdbuf();
        encodedTxt = encodedBuffer.str();
        encodedFile.close();
    }
}

int DecodeFile()
{
    string filename, txt;
    cout << "输入需要解压缩的文件名: ";
    cin >> filename;

    ifstream file(filename);

    if (file.is_open())
    {
        stringstream buffer;
        buffer << file.rdbuf();
        txt = buffer.str();
        file.close();
    }
    else
    {
        cout << "无法打开该文件！ " << filename << endl;
        return 1;
    }

    bool startDecode = false;
    int arr[256] = { 0 };
    int txtId = 0;
    for (int i = 0; i < txt.length(); i++)
    {
        if (txt[i] == '|')
        {
            startDecode = true;
            txtId = i + 1;
            break;
        }
        else
        {
            int tmp = 100 * (txt[i] - '0') + 10 * (txt[i + 1] - '0') + (txt[i + 2] - '0');
            i += 4;
            for (int j = 3; j >= 0; j--)
            {
                arr[tmp] += (txt[i] - '0') * pow(10, j);
                i++;
            }
        }
    }
    string encodedTxt = "";
    for (int i = txtId; i < txt.length(); i++)
    {
        encodedTxt += txt[i];
    }

    priority_queue<TreeNode*, vector<TreeNode*>, Compare> pq;

    for (int i = 0; i < 256; i++)
    {
        if (arr[i] > 0)
        {
            pq.push(new TreeNode(arr[i], static_cast<char>(i)));
        }
    }

    while (pq.size() != 1)
    {
        TreeNode* left = pq.top();
        pq.pop();
        TreeNode* right = pq.top();
        pq.pop();
        TreeNode* sum = new TreeNode(left->getWeight() + right->getWeight());
        sum->SetLeftChild(left);
        sum->SetRightChild(right);
        pq.push(sum);
    }

    TreeNode* root = pq.top();

    map<char, string> codes;
    GenerateCodes(root, "", codes);

    cout << "解压缩后的内容为：" << endl;
    cout << DecodeCodes(root, encodedTxt);

    return 0;
}

void Introduction()
{
    std::string courseInfo = "四川大学计算机学院 2024-2025 学年数据结构与算法分析课程实验课作业三";
    std::string name = "SQH";
    std::string studentID = "2023141460***";

    std::cout << "+----------------------------------------------------------------------------+" << std::endl;
    std::cout << "| " << courseInfo;
    std::cout << std::string(74 - courseInfo.length(), ' ') << " |" << std::endl;
    std::cout << "| 姓名：" << name;
    std::cout << std::string(68 - name.length(), ' ') << " |" << std::endl;
    std::cout << "| 学号：" << studentID;
    std::cout << std::string(68 - studentID.length(), ' ') << " |" << std::endl;
    std::cout << "+----------------------------------------------------------------------------+" << std::endl;

    for (int i = 0; i < 2; i++)
    {
        cout << endl;
    }
}

int main() 
{
    Introduction();
    char chooseFunc;
    cout << "选择输入压缩文件（E）或解压缩文件（D）：";
    cin >> chooseFunc;
    if (toupper(chooseFunc) == 'E')
    {
        EncodeFile();
    }
    else if (toupper(chooseFunc) == 'D')
    {
        DecodeFile();
    }
    

    return 0;
}
#ifndef TXTEDITOR
#define TXTEDITOR

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

void TxtI()
{
    cout << "指令集为：" << endl;
    cout << "          R：读取文本文件到缓冲区中，缓冲区中以前的任何内容将丢失，当前行是文件的第一行。" << endl;
    cout << "          W 或 S：将缓冲区的内容写入文本文件，当前行或缓冲区均不改变。" << endl;
    cout << "          I：插入单个新行，用户必须在恰当的提示符的响应中键入新行并提供其行号。" << endl;
    cout << "          D：删除当前行并移到下一行。" << endl;
    cout << "          F：从当前行开始，查找包含有用户请求的目标串的第一行。" << endl;
    cout << "          C：将用户请求的字符串修改成用户请求的替换字符串，仅在当前行中有效。" << endl;
    cout << "          Q：退出编辑器。" << endl;
    cout << "          H 或 ?：显示解释所有命令的帮助消息。" << endl;
    cout << "          N：下一行，在缓冲区中进一行。" << endl;
    cout << "          P：上一行，在缓冲区中退一行。" << endl;
    cout << "          B：开始，到缓冲区的第一行。" << endl;
    cout << "          E：结束，到缓冲区的最后一行。" << endl;
    cout << "          G：转到缓冲区中用户指定的行号。" << endl;
    cout << "          V：查看缓冲区的全部内容，显示到终端上。" << endl;
    cout << endl << endl << endl << endl << endl;
}

void Introduction()
{
    std::string courseInfo = "四川大学计算机学院 2024-2025 学年数据结构与算法分析课程实验课作业二";
    std::string name = "孙谦昊";
    std::string studentID = "2023141460321";

    std::cout << "+----------------------------------------------------------------------------+" << std::endl;
    std::cout << "| " << courseInfo;
    std::cout << std::string(74 - courseInfo.length(), ' ') << " |" << std::endl;
    std::cout << "| 姓名：" << name;
    std::cout << std::string(68 - name.length(), ' ') << " |" << std::endl;
    std::cout << "| 学号：" << studentID;
    std::cout << std::string(68 - studentID.length(), ' ') << " |" << std::endl;
    std::cout << "+----------------------------------------------------------------------------+" << std::endl;
    cout << endl;
}

class TxtEditor {
private:
    string fileName;
    string usedFileName;
    string tmpFileName;
    string insertLineString;
    string line;

    char command;

    int opeTimes = -1;

    int currentLineNo = 1;
    int maxLineNo = 0;

    int pages;
    int total;

    int insertLineNumber;
    int deleteLineNumber;
    int getLineNumber;

    bool firstReadFile = true;

    ifstream inFile;
    ofstream outFile;

    vector<string> lines;

public:
    TxtEditor() {};

    void PageAndTotal()
    {
        if (currentLineNo % 20 == 0)
        {
            pages = currentLineNo / 20;
        }
        else
        {
            pages = currentLineNo / 20 + 1;
        }

        if (maxLineNo % 20 == 0)
        {
            total = maxLineNo / 20;
        }
        else
        {
            total = maxLineNo / 20 + 1;
        }
    }

    void Screen(string command)
    {
        cout << endl;
        if (command == "Right")
        {
            if (maxLineNo == 0)
            {
                for (int i = 1; i <= 20; i++)
                {
                    cout << setw(2) << i << " | " << endl;
                }
            }
            else
            {
                PageAndTotal();

                int base = pages * 20;
                if (maxLineNo >= base)
                {
                    for (int i = 0; i < 20; i++)
                    {
                        if (i == currentLineNo - 1)
                        {
                            cout << "\033[32m" << setw(2) << i + (pages - 1) * 20 + 1 << " | " << lines[i] << "\033[0m" << endl;
                        }
                        else
                        {
                            cout << setw(2) << i + (pages - 1) * 20 + 1 << " | " << lines[i + (pages - 1) * 20] << endl;
                        }
                    }
                }
                else
                {
                    int i;
                    for (i = 0; i < maxLineNo - (pages - 1) * 20; i++)
                    {
                        if (i + (pages - 1) * 20 == currentLineNo - 1)
                        {
                            cout << "\033[32m" << setw(2) << i + (pages - 1) * 20 + 1 << " | " << lines[i + (pages - 1) * 20] << "\033[0m" << endl;
                        }
                        else
                        {
                            cout << setw(2) << i + (pages - 1) * 20 + 1 << " | " << lines[i + (pages - 1) * 20] << endl;
                        }
                    }
                    i += (pages - 1) * 20;
                    for (i; i < base; i++)
                    {
                        cout << setw(2) << i + 1 << " | " << endl;
                    }
                }

                cout << endl << "Page:" << setw(2) << pages << " ,Total:" << setw(2) << total << endl;
            }
        }
        else
        {
            TxtI();
        }
        cout << endl;
        cout << "----------------------------------------------------" << endl;
    }

    int ReadTxt(string tmpFileName)
    {
        if (firstReadFile)
        {
            usedFileName = tmpFileName;
            fileName = tmpFileName;
            firstReadFile = false;
        }
        else
        {
            if (fileName != tmpFileName)
            {
                cout << "读取" << tmpFileName << "将保存并删除缓冲区中" << fileName << "中的内容，是否要继续操作（Y/N）？";
                char judge = ' ';
                cin >> judge;
                if (toupper(judge) == 'N' && toupper(judge) != 'Y')
                {
                    cout << "放弃读取" << tmpFileName << endl;
                    return 1;
                }
                else
                {
                    usedFileName = fileName;
                    fileName = tmpFileName;
                    cout << "自动保存了" << usedFileName << "在缓冲区中的内容并";
                    WriteTxt(usedFileName);
                }
            }
        }

        inFile.open(fileName);
        if (!inFile.is_open())
        {
            cout << fileName << "不存在，自动创建相应文件" << endl;
            SaveTxt();
            inFile.open(fileName);
        }
        else
        {
            cout << "成功读取文件：" << fileName << endl;
            lines.clear();
            maxLineNo = 0;
            currentLineNo = 1;
            while (getline(inFile, line))
            {
                lines.push_back(line);
                maxLineNo++;
            }

            if (maxLineNo == 0)
            {
                lines.push_back("");
                maxLineNo++;
            }
            inFile.close();
        }
        usedFileName = fileName;
    }

    void WriteTxt(string file)
    {
        outFile.open(file);
        if (outFile.is_open())
        {
            for (const string& line : lines)
            {
                outFile << line << endl;
            }
            outFile.close();
        }
    }

    void SaveTxt()
    {
        outFile.open(fileName);
        outFile.close();
    }

    bool InsertTxt()
    {
        string newLine;
        int insertLineNo;
        cout << "当前有" << maxLineNo << "行。请输入需要在哪行前插入或在最后一行后插入？";
        cin >> insertLineNumber;
        if (insertLineNumber > maxLineNo + 1 || insertLineNumber < 0)
        {
            cout << "可插入的行数为1至" << maxLineNo << "之间或在最后一行后面进行插入！" << endl;
            return false;
        }
        else
        {
            currentLineNo = insertLineNumber;
            insertLineNo = insertLineNumber;
            cout << "输入需要插入的内容：";
            cin >> insertLineString;

            if (insertLineNo == maxLineNo + 1)
            {
                lines.push_back(insertLineString);
                maxLineNo++;
            }
            else
            {
                lines.push_back(" ");
                for (int i = maxLineNo; i >= insertLineNo; i--)
                {
                    lines[i] = lines[i - 1];
                }

                lines[insertLineNo - 1] = insertLineString;
                maxLineNo++;
            }

            return true;
        }

    }

    void DeleteTxt()
    {
        int deleteLineNo;
        cout << "当前有" << maxLineNo << "行。请输入需要删除那一行？";
        cin >> deleteLineNo;
        if (deleteLineNo > maxLineNo + 1 || deleteLineNo < 0)
        {
            cout << "可删除的行数为1至" << maxLineNo << "之间！" << endl;
        }
        else
        {
            for (int i = deleteLineNo - 1; i <= maxLineNo - 2; i++)
            {
                lines[i] = lines[i + 1];
            }
            maxLineNo--;
            currentLineNo = deleteLineNo;
            lines.pop_back();
        }
    }

    bool FindTxt()
    {
        string findTxt;
        cout << "输入需要查找的内容：";
        cin >> findTxt;

        if (findTxt.size() == 0)
        {
            cout << "输入内容不能为空！" << endl;
            return false;
        }
        else
        {
            for (currentLineNo = 1; currentLineNo <= maxLineNo; currentLineNo++)
            {
                SearchAndReplacement findTxtinFile(findTxt, lines[currentLineNo - 1]);
                findTxtinFile.GetNext();
                int k = findTxtinFile.Search();
                if (k != -1)
                {
                    cout << lines[currentLineNo - 1] << endl;
                    for (int j = 0; j < k; j++)
                    {
                        cout << " ";
                    }
                    cout << "^当前第" << currentLineNo << "行，需要查找的字符“" << findTxt << "”首次出现在此处。" << endl;

                    return true;
                }
            }
        }

        cout << "未在文件中找到匹配字符。" << endl;
        return false;

    }

    void ChageTxt()
    {
        string changedTxt;
        string changingTxt;
        cout << "输入需要替换的内容：";
        cin >> changedTxt;
        cout << "替换为：";
        cin >> changingTxt;
        if (changedTxt.size() == 0)
        {
            cout << "被替换内容不能为空！" << endl;
        }
        else
        {
            SearchAndReplacement changeTxtinFile(changedTxt, lines[currentLineNo - 1]);
            changeTxtinFile.GetNext();
            int k = changeTxtinFile.Search();
            int sizeofChangedTxt, sizeofChagingTxt, cha;
            if (k != -1)
            {
                sizeofChangedTxt = changedTxt.size();
                sizeofChagingTxt = changingTxt.size();
                lines[currentLineNo - 1].erase(k, sizeofChangedTxt);
                lines[currentLineNo - 1].insert(k, changingTxt);
            }
        }
    }

    string GetTxt(int getLineNo)
    {
        currentLineNo = getLineNo;
        return lines[getLineNo - 1];
    }

    void ViewTxt()
    {
        currentLineNo = 1;
        PageAndTotal();
        int getNextPage;
        cout << "输入查看的页数为：";
        cin >> getNextPage;
        if (0 < getNextPage && getNextPage <= total)
        {
            currentLineNo += (getNextPage - 1) * 20;
        }
    }

    int Run()
    {
        char command = ' ';
        char tmpCommand = 'H';

        while (tmpCommand == 'H' || tmpCommand == '?')
        {
            system("cls");
            Introduction();
            Screen("Wrong");
            cout << "请读取一个文件(R)，或退出(Q)：";
            cin >> tmpCommand;
            tmpCommand = toupper(tmpCommand);
            if (tmpCommand != 'R' && tmpCommand != 'Q')
            {
                tmpCommand = 'H';
            }
        }

        command = tmpCommand;

        system("cls");
        Introduction();
        Screen("Right");
        while (command != ' ')
        {
            switch (command)
            {
            case 'R':
                cout << "输入文件名：";
                cin >> tmpFileName;
                tmpFileName += ".txt";
                ReadTxt(tmpFileName);
                break;
            case 'W':
            case 'S':
                cout << "将缓冲区的内容写入文本文件..." << endl;
                WriteTxt(fileName);
                break;
            case 'I':
                InsertTxt();
                break;
            case 'D':
                DeleteTxt();
                break;
            case 'F':
                FindTxt();
                break;
            case 'C':
                ChageTxt();
                break;
            case 'Q':
                WriteTxt(fileName);
                exit(0);
                break;
            case 'H':
            case '?':
                system("cls");
                Introduction();
                Screen("Wrong");
                break;
            case 'N':
                if (currentLineNo != maxLineNo)
                {
                    GetTxt(currentLineNo + 1);
                }
                break;
            case 'P':
                if (currentLineNo != 1)
                {
                    GetTxt(currentLineNo - 1);
                }
                break;
            case 'B':
                GetTxt(1);
                break;
            case 'E':
                GetTxt(maxLineNo);
                break;
            case 'G':
                cout << "当前有" << maxLineNo << "行。请输入需要需要查看的行数：";
                cin >> getLineNumber;
                if (1 <= getLineNumber && getLineNumber <= maxLineNo)
                {
                    GetTxt(getLineNumber);
                }
                break;
            case 'V':
                ViewTxt();
                break;
            case 'U':
                break;
            case 'Z':
                break;
            default:
                cout << "未知指令。请正确输入如下指令集中的一个：" << endl;

                Screen("Wrong");
                break;
            }

            if (command != 'H' && command != '?')
            {
                system("cls");
                Introduction();
                Screen("Right");
            }
            cout << "请输入指令：";
            cin >> command;
            command = toupper(command);

        }

        return 0;
    }
};

#endif TXTEDITOR
#include <iostream>
#include <map>
#include <vector>
#include <sstream> // string stream
using namespace std;

int main()
{
    map<string, double> score_grade = {
        {"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5}, {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0}, {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0}};

    string s, spl;
    vector<string> subject;
    // subject[0]�� ����� subject[1]�� ���� subject[2]�� ���

    double total = 0, total_score = 0;
    // ���� ������ "���� x ��������" / "���� ����" ��.
    for (int i = 0; i < 20; i++)
    {
        getline(cin, s);    // �� �ٷ� �޾�
        stringstream ss(s); // ���ڿ� s �� stringstream ��ü ss�� �����
        while (getline(ss, spl, ' '))
        { // ss���� ���⸦ �������� �� �ܾ spl ������ ����
            subject.push_back(spl);
        }
        if (subject[2] == "P")
        {
            subject.clear();
            continue;
        }
        else
        {
            total_score += stod(subject[1]);                     // ������ ���� string to double �Լ� �̿�
            total += stod(subject[1]) * score_grade[subject[2]]; // map�Լ� �̿�
            subject.clear();
        }
    }

    cout << fixed;     // �Ǽ��� ���� �Ҽ������� ǥ��
    cout.precision(6); // ��Ȯ���� 6�ڸ�������
    cout << total / total_score;

    return 0;
}

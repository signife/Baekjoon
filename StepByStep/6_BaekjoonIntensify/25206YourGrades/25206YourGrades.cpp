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
    // subject[0]은 과목명 subject[1]은 학점 subject[2]는 등급

    double total = 0, total_score = 0;
    // 전공 평점은 "학점 x 과목평점" / "학점 총합" 임.
    for (int i = 0; i < 20; i++)
    {
        getline(cin, s);    // 한 줄로 받아
        stringstream ss(s); // 문자열 s 를 stringstream 객체 ss로 만들고
        while (getline(ss, spl, ' '))
        { // ss에서 띄어쓰기를 기준으로 한 단어씩 spl 변수에 저장
            subject.push_back(spl);
        }
        if (subject[2] == "P")
        {
            subject.clear();
            continue;
        }
        else
        {
            total_score += stod(subject[1]);                     // 학점의 총합 string to double 함수 이용
            total += stod(subject[1]) * score_grade[subject[2]]; // map함수 이용
            subject.clear();
        }
    }

    cout << fixed;     // 실수를 고정 소수점으료 표기
    cout.precision(6); // 정확도는 6자릿수까지
    cout << total / total_score;

    return 0;
}

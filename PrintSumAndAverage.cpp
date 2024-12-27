// PrintSumAndAverage.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <execution>
#include <string>
#include <cmath>

using namespace std;

pair<int* ,int> makeNumberArray();
template <typename T>
T doPrintAndGetT(const string_view& str);
const double getAverage(pair<const int* const, const int>& numberArray);
const int getSum(pair<const int* const, const int>& numberArray);

int main()
{
    pair<const int* const, const int> numberArray = makeNumberArray();

    std::cout << std::format( "sum :{}, average(소숫점 2자리 까지) : {}", getSum(numberArray), getAverage(numberArray) );

    delete[] numberArray.first;
}

pair<int*,int> makeNumberArray(){
    const int arraySize{ doPrintAndGetT<int>("입력할 숫자의 갯수를 입력해주세요:") };

    int* const numberArray = new int[arraySize];

    for (int index{ 0 }; index < arraySize; index++) {
        numberArray[index] = { doPrintAndGetT<int>("합과 평균을 구할 숫자를 입력해 주세요:") };
    }

    return { numberArray, arraySize };
}

template <typename T>
T doPrintAndGetT(const string_view& str) {
    T object{ 0 };
    cout << str << endl;
    cin >> object;
    while (cin.fail()) {
        cout << format("잘못된 형식입니다 다시 입력해주세요 \n{}", str) << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cin >> object;
    }
    cout << object << endl;
    return object;
}

const int getSum(pair<const int* const, const int>& numberArray) {
     return reduce(execution::par, numberArray.first, numberArray.first + numberArray.second, 0);
}

const double getAverage(pair<const int* const, const int>& numberArray) {
    return round(static_cast<double>(getSum(numberArray)) / static_cast<double>(numberArray.second) * 100) / 100;
}
// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.


#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include<math.h>
#include<string.h>
#include<tuple>
#include<bitset>
using namespace std;
//������
vector<int> QuickSortting(vector<int> a)
{
	int half = a.size() / 2;
	vector<int> Left, Right;
	int ahalf = a[half];
	if (a.size() == 1) return a;

	for (int q = 0; q < a.size(); q++) {

		if (half == q) continue;
		if (a[q] < a[half]) {

			Left.push_back(a[q]);
		}
		else {
			Right.push_back(a[q]);
		}

	}
	vector<int>rsum;


	if (Left.size() != 0)
		Left = QuickSortting(Left);

	for (int i = 0; i < Left.size(); i++) {
		rsum.push_back(Left[i]);
	}


	rsum.push_back(ahalf);


	if (Right.size() != 0)
		Right = QuickSortting(Right);

	for (int i = 0; i < Right.size(); i++) {
		rsum.push_back(Right[i]);
	}
	return rsum;
}



//
//class CTest
//{
//public:
//	explicit CTest() {
//		cout << "������" << endl;
//	}
//	virtual ~CTest() {
//		cout << "�Ҹ���" << endl;
//	}
//	//CTest *pTest = new CTest[10];
//
//	//delete[] pTest; //�Ҹ��ڰ� ������ [] ����� �����۵� �ȴ�.
//};


/*

 1. ����ġ n���� �ٽ��� ���̾� ȭ�� n�� ��

 2. ������ ����մϴ�.
	2-1. �������� ���ʺ��� �ܰ����� 10.9.8...
	2-2. ����, k���� ����ġ�� a�� ������ ���̾��� b���� ������ ��� ������ ȭ����  k ���� ���� ������ k���� �������ϴ�.
			  �� ���������� ������ ��������� ���
				�� a=b �ϰ�� ����ġ�� k���� ��������. k���� ���� ������ k���� ����� k�� 10 �϶� k�� 10�� ������ 10��

	2-3. ��� ���� ������ ���Ͽ� �������� ������ ����Ѵ�

3. ���������� �� ���� ������ ����ڷ� �����մϴ�, �θ��� ������� ����ġ�� ����ڷ� ��

4. ���̾��� ����Ҽ� ���°�� -1 ���� "������" ���ų� ���°��


���� ��Ȳ�� ����ġ�� ȭ�� n ���� �ٽ����̰� ���̾��� ȭ���� �������̴�.
���̾��� ����ġ�� ���� ū���� ���̷� �̱�� ���ؼ� n���� ȭ���� � ���� ������ ������ �ϴ��� ���Ϸ��Ѵ�.

ȭ���� ������ ���� �ڿ��� n

����ġ�� ���� ���ᰳ�� 10 -> 0  info


!! ���� ū������ �̰ܾ���

!!! ���� ū������ �̱�� ����� ����
*/

class A {
public:
	int b;
	operator A() {
		cout << "aa";
		A a;
		return a;
	}

	A operator +(A a) {

		return a;
	}

	//A operator ()(int a) {
	//	cout << "bb";
	//}
};
class MyClass : public  A
{
public:
	int bc;
};


int  main(void)
{

	//vector<int> citations = {3,0,6,1,5};
	//int answer = 0;
	//sort(citations.begin(), citations.end());
	//for (int i = 0; i < citations.size(); i++) {
	//	if (citations[i] >= i) {
	//		answer = citations.size() - i;
	//		break;
	//	}
	//}
	vector<string> babbling = {"ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"};
	vector<string> CanSay = { "aya","ye","woo","ma" };
	int answer = 0;
	
	for (auto a : babbling) {
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < CanSay.size(); j++) {

			}
		}
	}


	////run_lenth
	//string s = "aabbaccc";
	//int answer = 0;

	//string LenthSize = 0;
	//vector<int> sizeList = {};
	//string compare = "";
	//for (int i = 0; i < s.size() / 2; i++) {
	//	for (int j = 0; j < s.size(); j++) {
	//		compare = s.substr(j, i);

	//	}
	//}
}

#pragma region MyRegion
//MyClass m;
//m.b = 1;
//int MaxNum = 0;
//vector<vector<int>> Grap;
//�׷������� - �޴� ��ü �迭�� ����ū ���� �޴´�
// �� ũ�⸸ŭ �迭ũ�⸦ Ű���ش�. ����� ����

// [1.2] �� 1��2 2��1 �Ѵ� �迭�� ä���ش�.
// ��ã�� �˰����� ¥�ش�
// [1���� �����ؼ� [1,2] �� 2 �� [1] [3] [4] �� ������ ��������� ������ ������
// ũ�⸸ŭ �Ϲ� �迭����
// ���� �ϴ� ������� ���ڸ� �׹迭�� �Է�
// ���� Ŀ���� ��ǥ ����
//


//int rows = 6;
//int columns = 6;
//vector<vector<int>> Maps;
//vector<vector<int>> queries;
//vector<int> answer;

////((i-1) x columns + j)
//int a = 1;
//for (int i = 0; i < rows; i++) {
//	//queries.push_back(new vector<int>());
//	Maps.push_back(answer);
//	for (int j = 0; j < columns; j++) {
//		Maps[i].push_back(a++);
//	}
//}

//int xS = 0;
//int yS = 0;
//int xE = 0;
//int yE = 0;
//int xL = 0;
//int yL = 0;
//int ALenth = 0;
//for (int i = 0; i < queries.size(); i++)
//{
//	xS = queries[i][0];
//	yS = queries[i][1];
//	xE = queries[i][2];
//	yE = queries[i][3];
//	ALenth = ((xE - xS) + (yE - yS)) * 2;

//	while (ALenth-- >= 0)
//	{

//	}

//}


//	answer;
#pragma endregion

	//vector<int> citations = {3, 0, 6, 1, 5};
	//int answer = 0;
	//for (int i = 0; i < citations.size(); i++) {
	//	
	//}

	//return answer;


	/*vector<int> scoville;
	int K;

	int answer = 0;

	vector<int> MakeScoville = { scoville[0] };

	sort(scoville.begin(), scoville.end());
	int SumScoville = scoville[0];

	while (!(SumScoville >= K))
	{

		if (scoville.size() <= answer) return -1;
		answer++;
		if (MakeScoville.back() < scoville[answer]) {
			MakeScoville.push_back(MakeScoville.back() + (scoville[answer] * 2));

		}
		else {
			MakeScoville.push_back(scoville[answer] + (scoville[answer + 1] * 2));
		}

		SumScoville = MakeScoville[MakeScoville.size() - 1];
	}

*/






#pragma region Programers




string Number_partner(string X, string Y) {
	string answer = "";
	unordered_map<char, int>X_HM;
	unordered_map<char, int>Y_HM;
	for (int i = 0; i < X.size(); i++) {
		X_HM[X[i]]++;
	}

	for (int i = 0; i < Y.size(); i++) {
		Y_HM[Y[i]]++;
	}
	// �ߺ��񱳰� ���⳪ 1~9������ �׳� �ߺ��� ���Ÿ� ������
	//9���� 1���� ���غ��� ���������� ������
	for (auto a : X_HM) {
		for (auto b : Y_HM) {
			if (a.first == b.first) {
				int c = a.second > b.second ? b.second : a.second;
				for (int k = 0; k < c; k++) {
					answer += a.first;
				}
			}
		}
	}
	if (answer.size() == 0) return "-1";
	sort(answer.begin(), answer.end(), greater<>());

	if (answer[0] == '0') answer = "0";

	return answer;
}

vector<int> binary_Changeing(string s) {
	vector<int> answer = { 0,0 };
	while (s != "1")
	{
		answer[0]++;
		string s2 = s;
		//���߿� ã������ �ױ� �ޱ� ( Ư�� ���� ����)
		s2.erase(remove(s2.begin(), s2.end(), '0'), s2.end());
		answer[1] += (s.length() - s2.length());
		s = "";
		int lenth = s2.length();

		//���߿� ã������ �ױ� �ޱ� ( 10���� 2���� ��ȯ)
		while (lenth != 0)
		{
			if (lenth % 2 == 1)
				s.insert(0, "1");
			else
				s.insert(0, "0");
			lenth /= 2;
		}
	}
	return answer;
}

string String_Min_Max(string s) {
	string answer = "";
	int MinNum = 2147483647;
	int MaxNum = -2147483647;
	bool First = true;
	string numm = "";
	char Ch = ' ';

	for (int i = 0; i <= s.length(); i++) {

		if (i < s.length())
			Ch = s[i];

		if (Ch == ' ' || i == s.length()) {
			int Num = 0;
			Num = stoi(numm);
			if (First)
			{
				MinNum = Num;
				MaxNum = Num;
				Num = 0;
				numm = "";
				First = false;
				continue;
			}

			if (MinNum > Num) {
				MinNum = Num;
			}
			else if (MaxNum < Num) {
				MaxNum = Num;
			}
			Num = 0;
			numm = "";
		}
		else {
			numm += Ch;
		}
	}

	answer = { to_string(MinNum) + ' ' + to_string(MaxNum) };
	return answer;
}

string MBTI_(vector<string> survey, vector<int> choices) {

	/*
		char MBTI[4][2] = {
	{'R','T'},
	{'C','F'},
	{'J','M'},
	{'A','N'}
	};

	string solution(vector<string> survey, vector<int> choices) {
		string ans = "";
		map<char, int> score;

		for (int i = 0; i < survey.size(); ++i) {
			if (choices[i] < 4) {
				score[survey[i][0]] += (4 - choices[i]);
			}
			else {
				score[survey[i][1]] += (choices[i] - 4);
			}
		}

		for (int i = 0; i < 4; ++i) {
			if (score[MBTI[i][0]] >= score[MBTI[i][1]]) ans += MBTI[i][0];
			else ans += MBTI[i][1];
		}

		return ans;
	}



	���� �ϴ� Ǯ�̴� �̰Ŷ� ����ѵ� �� �������ϰ� Ǯ� ���� ���� �ȳ��� ���Ƽ� �� Ǯ������ �������
	const char�� �߰������� for������ �˻��� �񱳸� ������ �κ��� �����Ҽ��ִ����ΰ� ����

	*/


	string answer = "";
	std::unordered_map<char, int> MBTI_Data;
	MBTI_Data.insert(make_pair('R', 0));
	MBTI_Data.insert(make_pair('T', 0));

	MBTI_Data.insert(make_pair('C', 0));
	MBTI_Data.insert(make_pair('F', 0));

	MBTI_Data.insert(make_pair('J', 0));
	MBTI_Data.insert(make_pair('M', 0));

	MBTI_Data.insert(make_pair('A', 0));
	MBTI_Data.insert(make_pair('N', 0));
	const int ChoicesScore[7] = { 3,2,1,0,1,2,3 };

	for (int i = 0; i < survey.size(); i++) {
		int ChoiesNum = choices[i] - 1;

		if (ChoiesNum < 4) {
			MBTI_Data[survey[i][0]] += ChoicesScore[ChoiesNum];
		}
		else {
			MBTI_Data[survey[i][1]] += ChoicesScore[ChoiesNum];
		}
	}

	if (MBTI_Data['R'] < MBTI_Data['T']) answer += 'T';
	else answer += 'R';

	if (MBTI_Data['C'] < MBTI_Data['F']) answer += 'F';
	else answer += 'C';

	if (MBTI_Data['J'] < MBTI_Data['M']) answer += 'M';
	else answer += 'J';

	if (MBTI_Data['A'] < MBTI_Data['N']) answer += 'N';
	else answer += 'A';

	return answer;
}

bool bracket(string s)
{
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (')' == s[i] && num <= 0) {
			return false;
		}
		else if (')' == s[i]) {
			num--;
		}
		else
		{
			num++;
		}
	}
	if (num == 0)return true;
	return false;
}
//�̰Կ� 2�ܰ蹮���� 7��?
string JadenCaseString(string s) {

	if (97 <= s[0] && s[0] <= 122)s[0] -= 32;

	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == ' ') {
			if ('a' <= s[i] && s[i] <= 'z') {
				s[i] -= 32;
			}
		}
		else if ('A' <= s[i] && s[i] <= 'Z') {
			s[i] += 32;
		}
	}

	return s;
}

/*
	�� ��Ʈ ����Ǯ���µ�
	�� � ũ���� Ÿ���� �ᵵ �����÷ο찡 ����
	������ ���ص��� �ʿ��� ����
	( A + B ) % C  = (( A % C ) + ( B % C ))%C

	(50000 +50000 ) / @
	����
	50000/@ + 50000/@ �� ��� ���� ���̰� ª��.
*/
int pebonachi_1234567(int n) {
	long long a = 0;
	long long b = 1;
	long long answer = 0;
	while (n >= 2)
	{
		answer = (a + b) % 1234567;
		a = b % 1234567;
		b = answer % 1234567;
		n--;

	}
	return answer;
}

//�ٹٸ��� ������ - �ؽ�+Ȯ�� ��빮��
//�˰��� ����־��ϴ�����  2���� ������ �𸣱� �ϰڴµ�...
//hash_map ���������� for�� ���� �������߰�
// ���� ���̾������� �Ұ����� Ǯ��
int BarBarieMan_spi(vector<vector<string>> clothes) {
	unordered_map<string, int>Hash_map;
	int answer = 1;

	for (int i = 0; i < clothes.size(); i++)
		Hash_map[clothes[i][1]]++;

	for (auto a : Hash_map) {
		answer *= a.second + 1;
	}
	answer -= 1;

	return answer;
}

bool FindPrefix_Number(vector<string> phone_book) {

	bool answer = true;


	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size() - 1; i++)
	{
		int p = 0;
		for (int a = 0; a < phone_book[i].size(); a++) {
			p = (2 * p + phone_book[i][a]) % 2;
		}
		for (int j = i + 1; j < phone_book.size(); j++)
		{

			int p2 = 0;
			for (int a = 0; a < phone_book[i].size(); a++) {
				p2 = (2 * p2 + phone_book[j][a]) % 2;

			}

			if (p == p2 && phone_book[i].size() <= phone_book[j].size()) {

				for (int k = phone_book[i].size() - 1; k >= 0; k--) {
					if (phone_book[i][k] != phone_book[j][k]) goto a;
				}

				answer = false;
				goto B;
			}
			break;

		a:;

		}
	}
B:;


	/*
	 �ؽ� ��� �ϸ� �̷��� �����ϴ�.
	 ���� for�� ����Ѱ� ����.
	  unordered_map<string, int> hash_map;
	for(int i = 0; i < phone_book.size(); i++)
		hash_map[phone_book[i]] = 1;

	for(int i = 0; i < phone_book.size(); i++) {
		string phone_number = "";
		for(int j = 0; j < phone_book[i].size(); j++) {
			phone_number += phone_book[i][j];
			if(hash_map[phone_number] && phone_number != phone_book[i])
				answer = false;
		}
	}

	�̰� ����ϰ� �߾��µ� ����for���� �ȵ�����
	������ �����̶� �����ϴ�
	  sort(phoneBook.begin(), phoneBook.end());

	for ( int i = 0 ; i < phoneBook.size() - 1 ; i++ )
	{
		if ( phoneBook[i] == phoneBook[i+1].substr(0, phoneBook[i].size()) )
		{
			answer = false;
			break;
		}
	}
	*/
	return answer;
}

string LeapYear(int a, int b) {
	string answer = "";
	string month[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int month_day[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 1; i < a; i++) {
		b += month_day[i - 1];
	}

	answer = month[(b + 4) % 7];
	return answer;
}

vector<int>TakeTwoAdd(vector<int> numbers) {
	vector<int> answer;
	int PreviousNum = 0;
	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			answer.push_back(numbers[j] + numbers[i]);
		}
		PreviousNum = numbers[i];
	}

	sort(answer.begin(), answer.end());
	//��ġ�°� ����
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	return answer;
}
//������ ������ ��ŭ �ٸ������ Ǯ�̰� ����ϴ�. a���� b���� ����
long long  Numberadder(int a, int b) {
	if (a == b)return a;
	if (a > b) {
		int temp = a;
		a = b;
		b = temp;
	}
	long long answer = 0;
	for (int i = a; i <= b; i++) {
		answer += i;
	}

	/* ��Ʈ���� Ǯ��
	  if (a > b) a ^= b ^= a ^= b;
	answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;
	*/

	/* �ñ׸� �̿� (����Ǯ��)
	 return (long long)(a + b) * (abs(a - b) + 1) / 2;
	*/
	return answer;
}

int measurePlus(int left, int right) {
	int answer;
	for (int i = left; i <= right; i++)
	{
		int measureCount = 0;
		for (int j = 1; j <= i; j++) {

			if (i % j == 0) {
				measureCount++;
			}
		}
		measureCount % 2 == 0 ? answer += i : answer -= i;


	}
	return answer;
}

vector<int> FaillStages(int N, vector<int> stages) {
	// stages[a] = �����ִ� stage 
	// stages.size()����
	// stages[a] + 1 == n -> �� Ŭ������ ����
	// ������ = �����ص� Ŭ���� ���ѻ��/���������� ������ �÷��̾�
	// 2 1 2 6 2 4 3 3
	// 1 2 2 2 3 3 4 6
	// [1   3   2     1   0 1]   
   //    1/8  3/7  2/4 1/2  0    
	//    0.125 0.42 0.5 0.5 0
   //        1   2    3  4  5

	 //      0.5 0.5 0.42 0.125 0
	 //       3   4   2     1   5

	int finishPlayer = 0;
	vector<int> GameStage(N + 1);
	vector<float> SilpeaULL;
	vector<int> answer;
	for (int i = 0; i < stages.size(); i++) {
		GameStage[stages[i] - 1]++;
	}
	float afStage = 0;
	finishPlayer += GameStage[N];

	for (int i = N - 1; i >= 0; i--) {
		answer.push_back(N - i);
		finishPlayer += GameStage[i];
		SilpeaULL.insert(SilpeaULL.begin(), ((float)GameStage[i] / finishPlayer));
	}

	for (int i = 0; i < SilpeaULL.size(); i++) {
		for (int j = i + 1; j < SilpeaULL.size(); j++) {
			if (SilpeaULL[i] < SilpeaULL[j]) {

				float  temp = SilpeaULL[i];
				SilpeaULL[i] = SilpeaULL[j];
				SilpeaULL[j] = temp;

				int  INT_temp = answer[i];
				answer[i] = answer[j];
				answer[j] = INT_temp;
			}
			else if (SilpeaULL[i] == SilpeaULL[j] &&
				answer[i] > answer[j]) {
				int  INT_temp = answer[i];
				answer[i] = answer[j];
				answer[j] = INT_temp;
			}
		}

	}

	return answer;
}

int PocetmonGettoDaGe(vector<int> nums) {
	int answer = 0;
	sort(nums.begin(), nums.end());

	int getPocetmon = 0;
	int GetPocetmonCount = nums.size() / 2;
	for (int i = 0; i < nums.size(); i++) {
		if (GetPocetmonCount == 0)break;
		if (getPocetmon == nums[i]) continue;
		answer++;
		getPocetmon = nums[i];
		GetPocetmonCount--;
	}

	/*
	int solution(vector<int> nums) {
	unordered_set<int> s(nums.begin(), nums.end());
	return min(nums.size() / 2, s.size());
	*/
	return answer;
}

vector<string> _stringsort(vector<string> strings, int n) {
	for (int i = 0; i < strings.size(); i++) {
		for (int j = i + 1; j < strings.size(); j++) {

			if (strings[i][n] > strings[j][n]) {
				string  temp = strings[i];
				strings[i] = strings[j];
				strings[j] = temp;
			}
			else if (strings[i][n] == strings[j][n]) {
				if (strings[i] == strings[j])
				{
					continue;
				}
				for (int k = 0; k < (strings[i] > strings[j] ? strings[j].size() : strings[i].size()); k++) {
					if (strings[i][k] > strings[j][k] && i < j) {
						string  temp = strings[i];
						strings[i] = strings[j];
						strings[j] = temp;
						break;
					}
					else if (strings[i][k] < strings[j][k] && i < j) {
						break;
					}
				}
			}
		}
	}
	return strings;
}

string stringDescending(string s) {

	//sort (s.begin(), s.end(), greater<char>()); ª��Ǯ��

	// sort(s.rbegin(),s.rend());


	sort(s.begin(), s.end());
	for (int i = 0; i < s.size() / 2; i++) {
		char c = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = c;
	}
	return s;
}

int _3notation(int n) {
	int answer = 0;
	vector<int>as;
	while (n != 0)
	{
		as.push_back(n % 3);
		n /= 3;
	}
	for (int i = 0; i < as.size(); i++) {
		//3(n)�������� 10���� �纯ȯ�� 
		answer = answer * 3 + (as[i]);
	}
	return answer;
}

//n * (n+1) / 2 ���콺 ����...
//������ ����ؾ� �ϴ�����
long long AmusementPark(int price, int money, int count)
{

	long long SumPrice = 0;
	long long  nprice = 0;
	for (int i = 1; i <= count; i++)
	{
		nprice += price;
		(SumPrice += nprice);
	}
	SumPrice = SumPrice - money;
	return(SumPrice <= 0 ? 0 : SumPrice);
}

//¦���� �����ϱ� aa
int coupleDestroyer(string s)
{
	int answer = 0;
	vector<char> beh = {};

	if (s.size() % 2 != 0)return 0;

	for (int i = 0; i < s.size(); i++) {

		if (beh.size() > 0) {
			if (beh[beh.size() - 1] == s[i]) {
				beh.erase(beh.begin() + beh.size() - 1);
				answer++;
				continue;
			}
		}

		if (s[i] == s[i + 1]) {
			answer++; i++;
		}
		else {
			beh.push_back(s[i]);
		}
	}


	if (answer == s.size() / 2) answer = 1;
	else answer = 0;

	return answer;
}

int pluse_(vector<int> absolutes, vector<bool> signs) {

	int answer = 0;

	for (int i = 0; i < absolutes.size(); i++) {
		signs[i] ? answer += absolutes[i] : answer -= absolutes[i];
	}

	return answer;
}

//Ư���� �� �Ҽ����ϱ�
//�����佺�׳׽��� ü
int EraToseTenes_chea(int n) {
	int answer = 0;
	vector<bool> b(n + 1);
	for (int i = 2; i <= n; i++) {

		if (b[i] == false) {
			answer++;
			for (int j = 2; j * i <= n; j++) {
				b[(j * i)] = true;
			}
		}
	}
	return answer;
}

// 10����-> 3���� 124�� ��ȯ
string oenTwoFour_Wold(int a) {
	//�� �ް����� ġ�� ������������  Ǯ����
	string answer;
	char IND[3] = { '4','1','2' };
	vector<int> as;

	while (a != 0)
	{
		as.push_back(a % 3);
		if (a % 3 == 0) a--;
		a /= 3;
	}

	for (int i = as.size() - 1; i >= 0; i--) {

		answer += IND[as[i]];

	}
	return answer;
}

//���޺�Ʈ 2�� Ÿ�� Ż��
int LifeBoat(vector<int> people, int Limit) {
	int answer;
	int lef = 0;

	//��������Ѱ� ����Ѱź��� �ξ�����..
	sort(people.begin(), people.end());
	for (int i = people.size() - 1; i >= 0; i--)
	{
		//���� ª�� Ǯ�̴� for���ȿ� 4��
		/*
			for (int i = 0, j = N - 1; i <= j; i++) {
				�� i =left j = right ���ų� ������ ������ i++ -> �����ʿ��� ū�� ��
				 if (people[i] + people[j] <= limit) {
					j--;
					�� ���������Ͱ� ����ū�� ���� �����ϸ� ����ū�� ����;
					}

				  res++;
				����¬�� 1���̵� 2���̵� ��Ʈ�� Ÿ�ϱ� ++ ��Ÿ�°�찡 ������ ������ ++����� ��
			}
		*/
		//ereas �Լ��� �������� ���̴���
		// �ʹ� �����ϰ� �����߾���
		if (i - lef == 0) {
			break;
		}
		if (people[i] <= Limit / 2)
		{
			if (i + 1 % 2 == 0)
				answer += (i - lef) / 2;
			else {
				answer += (i - lef) / 2;
				answer++;
			}
			break;
		}
		if (people[i] + people[lef] > Limit || i == 0)
		{
			answer++;
		}
		else
		{
			lef++;
			answer++;
		}

	}
	return answer;
}

//�� ���̵� �����
string NewId(string new_id) {
	string id;
	for (int i = 0; i < new_id.size(); i++) {

		if (65 <= new_id[i] && new_id[i] <= 90) {
			id.push_back(new_id[i] + 32);
			continue;
		}

		if ((97 <= new_id[i] && new_id[i] <= 122) || (48 <= new_id[i] && new_id[i] <= 57) || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
		{
			if (!(i != 0 && id.size() && (id.back() == '.' && new_id[i] == '.')))
				id.push_back(new_id[i]);

		}
	}
	if (id[0] == '.')
		id.erase(id.begin());

	if (id.size() && id[id.size() - 1] == '.')
		id.erase(id.size() - 1);

	if (!id.size()) id += "a";

	if (id.size() && 16 <= id.size()) {
		id.erase(15);
		if (id[id.size() - 1] == '.')
			id.erase(id.size() - 1);
	}
	if (id.size() && id.size() <= 2) {
		for (int i = id.size(); i < 3; i++) {
			id.push_back(id.back());
		}
	}

	return id;
}

//��Ʈ ���� �������ϱ�
int DartGame(string dartResult) {
	int answer = 0;
	vector<int> Num;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] >= 48 && dartResult[i] <= 57) {
			if (dartResult[i] == 49 && dartResult[i + 1] == 48) {
				Num.push_back(10);
				i++;
				continue;
			}
			Num.push_back(dartResult[i] - 48);
		}

		if (dartResult[i] == 'S') { Num[Num.size() - 1]; }
		if (dartResult[i] == 'D') { Num[Num.size() - 1] = pow(Num[Num.size() - 1], 2); }
		if (dartResult[i] == 'T') { Num[Num.size() - 1] = pow(Num[Num.size() - 1], 3); }
		if (dartResult[i] == '#') { Num[Num.size() - 1] = Num[Num.size() - 1] * -1; }
		if (dartResult[i] == '*') {
			Num[Num.size() - 1] = Num[Num.size() - 1] * 2;
			if (Num.size() - 1 != 0)
				Num[Num.size() - 2] = Num[Num.size() - 2] * 2;
		}


	}

	for (auto num : Num) {
		answer += num;
	}
	return answer;
}

#pragma region vector ���� Ȯ��
//vector<int> v;
//vector<int> v1;
//for (int i = 0; i < 100; i++) {
//	v.push_back(i);
//	v1.reserve(i+1); //����Ȯ��
//	v1.push_back(i);
//	printf(" v = %d %d\n", (int)v.size(), (int)v.capacity());
//	printf(" v1 = %d %d\n", (int)v1.size(), (int)v1.capacity());
//}

#pragma endregion

int puppet_draw(vector<vector<int>> board, vector<int> moves) {

	vector<int> Basket;
	vector<int> BoardDepth(board[0].size());
	int answer = 0;

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] != 0 && (BoardDepth[j] == 0 && board[0][j] == 0)) BoardDepth[j] = i;
		}
	}

	for (auto num : moves) {
		if (BoardDepth[num - 1] >= board.size())
			continue;

		int Movescont = board[BoardDepth[num - 1]++][num - 1];

		if (Movescont == 0) continue;

		if (Basket.size() != 0) {
			if (Movescont == Basket.back())
			{
				answer += 2;
				Basket.pop_back();
				continue;
			}
		}
		Basket.push_back(Movescont);
	}
	return answer;
}

//�迭 �־��ֱ� -> ����Ʈ���� -> �ٽ� long �� �־��ֱ� ������ ����
// �ٸ���� 
/*
	string str = to_string(n);
	sort(str.begin(), str.end(), greater<char>());
	answer = stoll(str);

	�Ǵ� �׳� sort ��뤻��..


*/
long long QuickSort(long long n) {
	vector<int> a = {  };
	long long answer = 0;
	while (n != 0)
	{
		a.push_back(n % 10);
		n /= 10;
	}
	a = QuickSortting(a);


	answer = a[0];
	for (int i = 1; i < a.size(); i++) {
		answer += a[i] * pow(10, i);
	}
	return answer;
}

// �ڽ��� ���� ��� �¿� 

vector<int> SameNumErase(vector<int> arr) {
	vector<int> answer;
	int continuityNum = arr[0];
	answer.push_back(continuityNum);
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] == continuityNum) continue;
		else continuityNum = arr[i];
		answer.push_back(arr[i]);
	}
	return answer;
	//���� ª�� Ǯ�̴� �����̴�.(  arr.erase(unique(arr.begin(), arr.end()),arr.end());
}

vector<int> GCD_LCM(int m, int n) {

	vector<int> answer = { 0 };

	answer[0] = n >= m ? m : n;

	while ((n % answer[0] != 0) || (m % answer[0] != 0))
	{
		if (answer[0] == 1)break;
		answer[0]--;
	}
	answer.push_back((n * m) / answer[0]); //�ִ����� ���ϴ°��� n*m )/�ּҰ����
	return answer;
}

int Collera(int num) {
	long anum = num; //int ���� �����÷ο� ���鼭 488���� while����Ż���Ѵ�.
	long answer = 0;

	while (anum != 1 && answer++ <= 500)
	{

		if (anum % 2 == 0) long(anum /= 2);
		else anum = long(anum * 3 + 1);
	}

	if (answer > 500) answer = -1;

	return 0;
}

bool HasardNumber(int x) {
	int _x = x;
	bool answer = false;
	int hasad = 0;

	while (x != 0)
	{
		hasad += x % 10;
		x /= 10;
	}

	if (_x % hasad == 0) { answer = true; }
	return answer;
}

bool BaseString(string s) {
	bool answer = true;
	if (s.size() == 4 || s.size() == 6) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < 48 || 57 < s[i])	answer = false;
		}
	}
	else {
		answer = false;
	}
	return answer;
}

string seiserString(string s, int n) {

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') { continue; }

		if (int(s[i]) + n > 122) {
			s[i] = n + (s[i] - 26);
			continue;
		}
		if (90 < s[i] + n && (s[i]) < 91) {
			s[i] = n + (s[i] - 26);
			continue;
		}
		s[i] += n;
	}
	return s;

}

string WeirdString(string s) {

	int o = 0;
	for (int i = 0; i < s.size(); i++) {

		if (s[i] == ' ') {
			o = 0;
			continue;
		}

		if (o % 2 == 0 && s[i] >= 97 && s[i] <= 122)
			s[i] -= 32;
		else if (o % 2 != 0 && s[i] <= 90 && s[i] >= 65)
			s[i] += 32;
		o++;
	}

	return s;
}

vector<int> Reported(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;
	vector<int> Reported_person; //�Ű���� Ƚ��
	vector<bool> Reported_persons; //�Ű� ���ѻ���� �����λ��
	vector<vector<bool>> ReportCount;//  �Ű��� ��� - �Ű���ѻ����
	map<string, int> ID; //��� �̸��� ��ȣ



	for (int i = 0; i < id_list.size(); i++) {

		ID.insert(make_pair(id_list[i], i)); //map�� �־��ְ�
		ReportCount.push_back({}); // �ʱ�ȭ
		Reported_person.push_back({}); // �ʱ�ȭ
		Reported_persons.push_back({}); // �ʱ�ȭ
		answer.push_back({}); // �ʱ�ȭ

		for (int j = 0; j < id_list.size(); j++) {
			ReportCount[i].push_back(false); //fals�� �־��ְ�
		}

	}

	for (int i = 0; i < report.size(); i++) {

		string reprotMessage; //���� �̸�
		string Repoter1;
		for (int j = 0; j < report[i].size(); j++) {
			if (report[i][j] == ' ') { // �����̽��� - ����
				Repoter1 = reprotMessage; //�Ű��ѻ�� ����
				reprotMessage = ""; //�ʱ�ȭ
				continue;
			}
			reprotMessage += report[i][j];
		}
		// Repoter1 �Ű��ѻ��  reportMessage //�Ű��� �г���

		if (reprotMessage == Repoter1) {
			continue; //�����̸� ����
		}

		if (ReportCount[ID.find(Repoter1)->second][ID.find(reprotMessage)->second] == false)
		{
			ReportCount[ID.find(Repoter1)->second][ID.find(reprotMessage)->second] = true;
			Reported_person[ID.find(reprotMessage)->second]++;

			if (Reported_person[ID.find(reprotMessage)->second] >= k)
			{
				Reported_persons[ID.find(reprotMessage)->second] = true; //k���� ū�� ������ ��
			}
		}
	}

	for (int i = 0; i < id_list.size(); i++) {
		for (int j = 0; j < id_list.size(); j++) {
			if (ReportCount[i][j] == true && Reported_persons[j] == true) {
				answer[i]++;
			}
		}
	}

	return answer;
}

//������ ������ �𸣰��� (2�������� ����ϳ�
/*


	for (int i = 0; i < report.size(); i++) {

		string reprotMessage; //���� �̸�
		vector<bool>  *Reporter1 =nullptr; // �̸��� �´� �Ű��ڹ迭
		for (int j = 0; j < report[i].size(); j++) {
			if (report[i][j] == ' ') { // �����̽��ٷ� �ʱ�ȭ
				Reporter1 = &ReportCount[ID.find(reprotMessage)->second]; //ID[reprotMessage]
				reprotMessage = "";
				continue;
			}
			reprotMessage += report[i][j];

		}
		cout << &Reporter1[ID.find(reprotMessage)->second] ;
	}

	��?
*/

vector<int>MO_U_test(vector<int> answers) {
	vector<int> answer;
	answer = { 0 };

	vector<vector<int>> anserers = {
	{ 1,2,3,4,5 },
	{ 2,1,2,3,2,4,2,5},
	{ 3,3,1,1,2,2,4,4,5,5 } };

	int AnswerersAnser[3] = { 0, };
	int j = 0;
	for (int o = 0; o < 3; o++) {
		for (int i = 0; i < answers.size(); i++) {

			if (answers[i] == anserers[o][j])
			{
				AnswerersAnser[o]++;
			}
			j++;
			if (j == anserers[o].size()) j = 0;
		}
		j = 0;
	}

	int count = 0;
	for (int o = 0; o < 3; o++) {
		if (count < AnswerersAnser[o]) {
			count = AnswerersAnser[o];
			answer.clear();
			answer.push_back(o + 1);
		}
		else if (count == AnswerersAnser[o])answer.push_back(o + 1);

	}
	return answer;
}

/*
int Joystick(string name) {

	//�̵���ġ�� ������ġ - + ������ġ
	//  ZAQ <- ���� pos��ġ X    23         25 0 16              2�� ������ġ 1��ĭ z        2�� ������ �ѹ��̵� z ���� A�� �ѹ�  2��ĭ a     11�� ��ĭ �̵� A > Q   16 - 0 =16, 0 -> 25-16 = (9+1),  + 1ĭ�̵�

	/*


	int answer = 0;

	const char a[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	const int AlphaBetMax = 26; //0~25
	int NowAlphabetPos = 0;
	int cursor = 0;

	return answer;
}
	*/

int Gymsuit(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> An(n);

	for (int i = 0; i < lost.size(); i++) An[lost[i] - 1] = 1;

	for (int i = 0; i < reserve.size(); i++)
	{
		if (An[reserve[i] - 1] == 1) {
			An[reserve[i] - 1] = 0;
			continue;
		}
		An[reserve[i] - 1] = 2;
	}

	for (int i = 0; i < n; i++)
	{
		if (An[i] == 1) {

			if (An[i - 1] == 2) {
				An[i] = 0;
				An[i - 1] = 0;
			}
			else if (n > (i + 1) && An[i + 1] == 2) {
				An[i] = 0;
				An[i + 1] = 0;
			}
		}

		if (An[i] == 0 || An[i] == 2) answer++;
	}



	return answer;
}

/*

 1�� - 6�� ��ġ
 2�� - 5�� ��ġ
 3�� - 4�� ��ġ
 4�� - 3�� ��ġ
 5�� - 2�� ��ġ
	���� ��÷ 6

  0�� Ʋ���ų� �¾�����

   ��÷��ȣ [31 10 45 1 6 19]
   �����ȣ [31  0 44 1 0 25]

  o �� x o �� x   �ΰ� ����, �ΰ� ����, �ΰ� ����

			 �� �� x�϶� 2�� ���� 5��
			 �� �� o�϶� 4������ 3��

*/

vector<int> LottosNum(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int Rank[] = { 6,6,5,4,3,2,1 };
	int unrecognizableNum = 0; //0���� ��ŭ ���ϰų� ����
	int answerCount = 0;

	for (int i = 0; i < lottos.size(); i++) {

		if (lottos[i] == 0) {
			unrecognizableNum++; //0�̸� continue
			continue;
		}

		for (int j = 0; j < lottos.size(); j++) {

			if (lottos[i] == win_nums[j]) {
				answerCount++;
				break;
			}
		}
	}

	answer.push_back(Rank[(answerCount + unrecognizableNum)]);
	answer.push_back(Rank[answerCount]);

	return answer;
}
//���α׷��ӽ� �ؽ�1
void HashFunc1() {
	std::vector<std::string> participant = { "mislav", "test", "mislav" ,"mislav" };
	std::vector<std::string> completion = { "mislav", "mislav","test" };
	std::string Retire;
	std::unordered_map<std::string, int> Completions;

	for (int i = 0; i < completion.size(); i++) {
		if (Completions[completion[i]] == 0)
			Completions.insert(std::make_pair(completion[i], Completions.at(completion[i])++));
		else {
			Completions.at(completion[i])++;
		}
	}
	for (int i = 0; i < participant.size(); i++) {
		if (Completions[participant[i]]) {
			Completions.at(participant[i])--;
		}
		else {
			Retire = participant[i];
			break;
		}
	}

}

#pragma endregion
//���� ������
void func() {
	int MabangZinSize = 0, i, j;
	bool M = true;
	std::vector<std::vector<char>> vec;
	std::cin >> MabangZinSize;
	for (i = 0; i < MabangZinSize; i++) {
		std::vector<char> vec1;
		vec.push_back(vec1);
		char ch;
		for (j = 0; j < MabangZinSize; j++) {
			std::cin >> ch;
			vec[i].push_back(ch);
		}
		for (j = 0; j < i + 1; j++) {
			if (vec[i][j] != vec[j][i]) {
				M = false;
			}
		}

	}
	(M == false) ? std::cout << "NO" : std::cout << "YES";
}


/*
�帣���� ����� �뷡�� 2���� ��ƾ���
1�帣 2�뷡
  �뷡�� ���� ������ȣ�� ����

1. �帣 ���� -> ���� �뷡�� 1���� ��
2. �帣 ������ ���� -> 2��ȸ,1��ȸ ������ ����
3. �帣 ������ Ƚ���� ������ -> ������ȣ�� �����뷡 ���� (������ȣ�� �迭��ȣ)

�뷡 �带 genres / �뷡�� ���Ƚ�� plays �� �־����� �轺Ʈ
�ٹ��� �� �뷡 ���� ��ȣ�� ������� ����

genres[i]�� ������ȣ�� i�� �뷡�� �帣�Դϴ�.
plays[i]�� ������ȣ�� i�� �뷡�� ����� Ƚ���Դϴ�.
genres�� plays�� ���̴� ������, �̴� 1 �̻� 10,000 �����Դϴ�.
�帣 ������ 100�� �̸��Դϴ�.
�帣�� ���� ���� �ϳ����, �ϳ��� � �����մϴ�.
��� �帣�� ����� Ƚ���� �ٸ��ϴ�


*/

//vector<int>  HashFunc2() {
//	vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
//	vector<int> plays = { 500, 600, 150, 800, 2500 };
//	vector<int> answer;
//	unordered_map<string, vector<int>> Map;
//	for (int i = 0; i < genres.size(); i++) {
//		Map.insert(make_pair(genres[i], 0) );
//		Map[genres[i]][i]=(plays[i]);
//	}
//
//
//	return answer;
//}

	//vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
	//vector<int> plays = { 500, 600, 150, 800, 2500 };
	//vector<int> answer;
	//unordered_map<string, vector<int>> Map;
	//for (int i = 0; i < genres.size(); i++) {
	//	Map.insert(make_pair(genres[i], 0));
	//	//Map[genres[i]][i] = (plays[i]);
	//	Map[genres[i]].push_back(plays[i]);
	//}
	//for (int i = 0; i < Map.size(); i++) {
	//	cout<<	Map["pop"][i] <<endl;
	//}


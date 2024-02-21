#include<queue>
#include <unordered_map>
#include<vector>
#include<iostream>
#include<map>
#include <map>
#include <string>
#include <iostream>
#include <queue>
#include <algorithm>
#include<math.h>
#include<string.h>
#include<tuple>
#include<bitset>
#include <functional>
using namespace std;

void sortQueue_xy() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	int num = 0;
	cin >> num;
	int a=0, b=0;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		pq.push({ a,b });
	}

	while (!pq.empty()) {
		cout << pq.top().first << pq.top().second << endl;
		pq.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(NULL);
	sortQueue_xy();
	return 0;
}

#pragma region Programmers
//올바른 괄호 lv2
bool Right_Garho{
	int garho = 0;
	bool answer = true;
	for (auto i : s) {
		if (i == '(')garho++;
		else garho--;

		if (garho < 0) {
			answer = false;
		}

	}

	if (garho != 0) answer = false;
return answer;
}
//나누어 떨어지는 숫자 배열 lv1
vector<int> falling_Nums(vector<int> arr, int divisor) {
	vector<int> answer;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % divisor == 0 && arr[i] >= divisor) {
			answer.push_back(arr[i]);
		}
	}
	sort(answer.begin(), answer.end());

	if (answer.size() == 0)answer.push_back(-1);

	return answer;
}
//두 정수 사이의 합 lv1
long long between_Sum (int a, int b) {
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
	return answer;
}
//문자열 내마음대로 정렬하기 lv1
vector<string> my_Like_sort(vector<string> strings, int n) {

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
//내자열 내 p와y의 개수 lv1
bool myPandY(string s)
{
	int num = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'p' || s[i] == 'P')num++;
		else if (s[i] == 'y' || s[i] == 'Y')num--;
	}

	return !num;
}
//문자열 내림차순으로 배치하기 lv1
string String_Lower(string s) {
	sort(s.begin(), s.end());
	for (int i = 0; i < s.size() / 2; i++) {
		char c = s[i];
		s[i] = s[s.size() - 1 - i];
		s[s.size() - 1 - i] = c;
	}
	return s;
	/*
	string solution(string s) {
	sort(s.rbegin(),s.rend());
    return s;
}
	*/
}
//문자열 다루기 기본 lv1
bool String_Daruda(string s) {
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
//서울에서 김서방 찾기
string Hey_Kim(vector<string> seoul) {
	string name = "Kim";
	string answer = "김서방은 ";
	for (int i = 0; i < seoul.size(); i++) {
		if (seoul[i].size() != 3)continue;
		if (seoul[i].compare(name) == 0)
			answer += to_string(i);
	}

	answer += "에 있다";

	return answer;
}
//소수 찾기
//에라토스테네스
int Ill_Find_you(int n) {
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
//수박수박수박수박수박수?
string subacksu(int n) {
	string suback = "수박";
	string answer = "";
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) answer += ("수");
		else answer += ("박");
	}

	return answer;
}
//문자열을 정수로 바꾸기
int  Stephen_Vincent_String_Strange(string s) {
	int answer = 0;
	int k = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		k++;
		if (s[i] == '-' || s[i] == '+')break;
		answer += (s[i] - 48) * pow(10, k - 1);
	}
	if (s[0] == '-') answer *= -1;

	return answer;
}
//시저 암호
string im__Monkey(string s, int n) {

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
//약수의 합
int we_are_weak(int n) {
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) answer += i;
	}

	return answer;
}
//이상한 문자 만들기
string String_you(string s) {
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
//자리수 더하기
int jarisu(int n)
{
	int answer = 0;
	while (n != 0)
	{
		answer += n % 10;
		n /= 10;
	}

	return answer;
}
//자리수 뒤집어 배열로 만들기
vector<int> usiraj(long long n) {
	vector<int> answer = {  };
	while (n != 0)
	{
		answer.push_back(n % 10);
		n /= 10;
	}
	return answer;
}
//정수 내림차순으로 배치하기
vector<int> make_QuickSortting(vector<int> a);
//퀵소트 사용
long long ne_leu_gan_DAAAAAAA(long long n) {
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
vector<int> make_QuickSortting(vector<int> a)
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
//정수 제곱근 판별
long long is_this_jeghob(long long n) {
	long long answer = 0;


	answer = sqrt(n);
	if (answer * answer != n) return -1;
	answer = (answer + 1) * (answer + 1);

	return answer;
}
//제일 작은 수 제거하기
vector<int> Minimi_Killer(vector<int> arr) {
	int MinNum = arr[0];
	int MinIndexNum;


	for (int i = 0; i < arr.size(); i++) {
		if (MinNum >= arr[i]) {
			MinNum = arr[i];
			MinIndexNum = i;
		}
	}
	arr.erase(arr.begin() + MinIndexNum);
	if (arr.size() == 0) return { -1 };
	if (arr.size() == 1 && arr[0] == 10)return { -1 };
	return arr;
}
//짝수와홀수
string hall(int num) {
	string answer = "";
	if (num % 2 == 0) answer = "Even";
	else answer = "Odd";
	return answer;
}
//최대값과최솟값 lv2
string minimum_Max(string s) {
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
//최대공약수와 최소공배수
//다른 좋은 방법이 더있음 ( 대학 학습지 에서 확인한방법 추가할것)
vector<int>Greatest_common_divisorand_least_common_multiple(int n, int m) {

	vector<int> answer = { 0 };

	answer[0] = n >= m ? m : n;
	//while 문에 %들어가면 다른수가 나옴
	while ((n % answer[0] != 0) || (m % answer[0] != 0))
	{
		if (answer[0] == 1)break;
		answer[0]--;
	}
	answer.push_back((n * m) / answer[0]);
	return answer;
}
//콜라츠 추측
int colrach(int num) {
	long anum = num;
	long answer = 0;

	while (anum != 1 && answer++ <= 500)
	{

		if (anum % 2 == 0) long(anum /= 2);
		else anum = long(anum * 3 + 1);
	}

	if (answer > 500) answer = -1;

	return answer;
}
//평균 구하기
double average_save(vector<int> arr) {
	double answer = 0;

	for (int i = 0; i < arr.size(); i++) answer += arr[i];

	answer /= arr.size();
	return answer;
}
//피보나치 수
//%1234567을 값 사이사이 해주어 너무 큰값 계산을 안하게 하는 방법
// 마지막에 해버림 숫자가 넘어가버린다.
int pibonarch(int n) {
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
//하샤드 수
bool hashard(int x) {
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
//핸드폰 번호 가리기
string hide_on_phone(string phone_number) {
	string answer = "";

	for (int i = 0; i < phone_number.size(); i++) {
		if (4 >= phone_number.size() - i)answer.push_back(phone_number[i]);
		else {
			answer.push_back('*');
		}
	}

	return answer;
}
//행렬의 덧셈
vector<vector<int>> plus_plus_plus_plus(vector<vector<int>> arr1, vector<vector<int>> arr2) {
	vector<vector<int>> answer;


	for (int i = 0; i < arr1.size(); i++) {
		answer.push_back(vector<int>());
		for (int j = 0; j < arr1[i].size(); j++) {
			answer[i].push_back(arr1[i][j] + arr2[i][j]);
		}
	}
	return answer;
}
//JadenCase lv2
//왜 2렙인지 모름
string jaden(string s) {

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
//x만큼 간격이 있는 n개의 숫자
vector<long long> xxxxxxxxx_9(int x, int n) {
	vector<long long> answer;
	for (int i = 0; i < n; i++) {
		answer.push_back((i + 1) * x);
	}

	return answer;
}
//직사각형 별찍기
int star_square(void) {
	int a;
	int b;
	scanf("%d %d", &a, &b);
	int i = 0;
	int j = 0;
	for (i = 0; i < b; i++) {
		for (j = 0; j < a; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
//짝지어 제거하기
int Love_Remove(string s)
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
//소수 만들기
int make_minority(vector<int> nums) {
	int answer = 0;

	sort(nums.begin(), nums.end());
	int n = nums[nums.size() - 1] + nums[nums.size() - 2] + nums[nums.size() - 3];
	vector<bool> b(n + 1);
	for (int i = 2; i <= n; i++) {

		if (b[i] == false) {
			for (int j = 2; j * i <= n; j++) {
				b[(j * i)] = true;
			}
		}
	}
	for (int i = 0; i < nums.size() - 2; i++) {
		for (int j = i + 1; j < nums.size() - 1; j++) {
			for (int k = j + 1; k < nums.size(); k++) {
				if (!b[nums[i] + nums[j] + nums[k]]) {
					answer++;
				}
			}
		}
	}

	return answer;
}
//예산
int budget(vector<int> d, int budget) {
	int answer = 0;
	int a = 0;
	sort(d.begin(), d.end());

	for (int i = 0; i < d.size(); i++)
	{
		if (d[i] + a > budget)
		{
			break;
		}
		a += d[i];
		answer++;
	}
	return answer;
}
//[1차]비밀지도
vector<string> secret_map(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	int a;
	for (int i = 0; i < n; i++) {
		a = arr1[i] | arr2[i];
		int b = n;
		while (b != 0)
		{
			if (a % 2 == 0) {

				answer[i].insert(answer[i].begin(), ' ');

			}
			else {
				answer[i].insert(answer[i].begin(), '#');
			}
			a /= 2;
			b--;
		}

	}

	return answer;
}
//[1차] 닷트
int dart(string dartResult) {
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
//완주하지 못한선수 
string Im_not_loser(vector<string> participant, vector<string> completion) {
	std::string Retire;
	std::unordered_map<std::string, int> Completions;
	for (int i = 0; i < completion.size(); i++) {
		Completions[completion[i]]++;
	}
	for (int i = 0; i < participant.size(); i++) {
		try
		{
			if (Completions.at(participant[i]) > 0) {
				Completions.at(participant[i])--;
			}
			else {
				Retire = participant[i];
				break;
			}
		}
		catch (const std::exception&)
		{
			Retire = participant[i];
			break;
		}

	}
	return Retire;
}
// 전화 번호 목록 lv2
// goto문 써서 탈출 하는식으로 써봄 편하긴하다
bool phone_book(vector<string> phone_book) {
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

			int p2;
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


	return answer;
}
// 의상 
// 너무쉬웠음
int clothes(vector<vector<string>> clothes) {
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
//베스트앨범 lv3 
//포인터 방식으로도 풀수있지만 난이도가 높아지며 해시문제라 해시로 풀었음
#define PairVec pair<string,pair<vector<pair<int, int>>, int>>
#define PairT  pair<int, int>
bool sqrtInTuple(PairT& a, PairT& b)
{
	return a.first > b.first;
}
bool sqrtInHashSize(const PairVec& Hash_mapa, const PairVec& Hash_mapb) {
	return (Hash_mapa.second.second) > (Hash_mapb.second.second);
}
vector<int> Favorite_song(vector<string> genres, vector<int> plays) {
	unordered_map <string, pair<vector<pair<int, int>>, int>> Hash_map;
	vector<int> answer = {};
	for (int i = 0; i < genres.size(); i++)
	{
		Hash_map[genres[i]].first.push_back({ plays[i], i });
		Hash_map[genres[i]].second += plays[i];
	}

	vector<PairVec> vec_P(Hash_map.begin(), Hash_map.end());
	sort(vec_P.begin(), vec_P.end(), sqrtInHashSize);

	for (int i = 0; i < vec_P.size(); i++) {
		sort(vec_P[i].second.first.begin(), vec_P[i].second.first.end(), sqrtInTuple);
	}
	for (int i = 0; i < vec_P.size(); i++)
	{
		int P_Number = 0;
		for (int j = 0; j < vec_P[i].second.first.size() && j < 2; j++) {
			P_Number = vec_P[i].second.first[j].second;
			answer.push_back(P_Number);
		}
	}
	return answer;
}
//기능개발 lv2
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer = { 0 };
	int count = 1;
	for (int i = 0; i < speeds.size(); i++) {
		if ((count * speeds[i]) + progresses[i] >= 100) {
			answer[answer.size() - 1]++;
			continue;
		}
		if (answer[answer.size() - 1] != 0)
			answer.push_back(0);
		count++;
		i--;
	}
	return answer;
}
// 프로세스 lv2
bool sqrtInPair(pair<int, int>& a, pair<int, int>& b)
{
	return a.first > b.first;
}
int solution(vector<int> priorities, int location) {
	queue<pairs> Pros;
	int answer = 1;
	int Bigger = 0;
	for (int i = 0; i < priorities.size(); i++)
	{
		Pros.push(make_pair(priorities[i], i));
	}
	sort(priorities.begin(), priorities.end(), greater<>());
	while (true) {
		if (Pros.front().first == priorities[answer - 1] && Pros.front().second == location)break;
		if (Pros.front().first == priorities[answer - 1]) {
			answer++;
			Pros.pop();
			continue;
		}
		Pros.push(Pros.front());
		Pros.pop();
	}

	return answer;
}
//더 맵게
int MoreSpicy(vector<int> scoville, int k) {

	int answer = 0;
	priority_queue<int, vector<int>, greater<int>>  _Scoville;
	_Scoville = { scoville.begin(),scoville.end() };
	while (!_Scoville.empty())
	{
		int a = 0, b = 0;

		a = _Scoville.top();
		_Scoville.pop();

		if (a >= k)break;

		b = _Scoville.top();
		_Scoville.pop();

		if ((a + (b * 2)) < k) {
			if (_Scoville.empty()) {
				return -1;
			}

		}
		_Scoville.push((a + (b * 2)));

		answer++;
	}
	return answer;
}
//K번째수
vector<int> kn(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		vector<int> a;
		if (commands[i][0] == commands[i][1]) {

			answer.push_back(array[commands[i][0] - 1]);
			continue;
		}
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
			a.push_back(array[j]);
		}
		sort(a.begin(), a.end());
		answer.push_back(a[commands[i][2] - 1]);
	}


	return answer;
}
//모의고사
vector<int> mouegosa(vector<int> answers) {
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
		else if (count == AnswerersAnser[o]) {
			answer.push_back(o + 1);
		}
	}
	return answer;
}
//체육복
int jeuckbock(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> An(n);


	for (int i = 0; i < lost.size(); i++)
	{
		An[lost[i] - 1] = 1;
	}
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
//구명보트 lv2
int helpbort(vector<int> people, int Limit) {
	int answer = 0;
	int lef = 0;
	sort(people.begin(), people.end());
	for (int i = people.size() - 1; i >= 0; i--)
	{
		if (i - lef <= 0) {
			answer++;
			break;
		}
		if (people[i] + people[i] <= Limit)
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
//실패율
vector<int> fail(int N, vector<int> stages) {
	// stages[a] = 깨고있는 stage 
	// stages.size()유저
	// stages[a] + 1 == n -> 다 클리어한 유저
	// 실패율 = 도달해도 클리어 못한사람/스테이지에 도달한 플레이어
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
//가장 먼노드
unordered_map<int, vector<int>> map;
unordered_map<int, int> ML;
queue<int> bfs_Queue;
int bigNum = 0;
void BFS_GrapFind() {

	while (!bfs_Queue.empty())
	{
		int a = bfs_Queue.front();
		bfs_Queue.pop();

		for (int i = 0; i < map[a].size(); i++)
		{
			if (ML[map[a][i]] == 0 || ML[map[a][i]] > ML[a] + 1) {
				ML[map[a][i]] = ML[a] + 1;
				if (bigNum < ML[a] + 1)  bigNum = ML[a] + 1;
				bfs_Queue.push(map[a][i]);
			}
		}
	}
}
int so_far(int n, vector<vector<int>> edge) {
	int answer = 0;
	for (auto node : edge) {
		if (map.find(node[0]) == map.end())
		{
			map[node[0]] = {};
			ML[node[0]] = 0;
		}
		map[node[0]].push_back(node[1]);
		map[node[1]].push_back(node[0]);
	}
	bfs_Queue.push(1);
	BFS_GrapFind();
	for (auto m : ML) {
		if (m.first != 1 && m.second == bigNum)answer++;
	}
	return answer;
}
//멀쩡한 사각형
long long saGack_bro(int w, int h) {
	//사각형을 나눠서 칸마다 계산하다가 결국 수학식을 확인했음
	return  (long long)w * h - (ceil(double(h) / w / 2) * w);
}
//크레인 인형뽑기 게임
int crain_gatCha(vector<vector<int>> board, vector<int> moves) {
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
//키패드 누르기
string keypad(vector<int> numbers, string hand) {
	string answer = "";

	vector<char> KeyPed = { '0','L','2','R','L','5','R','L','8','R' };
	int LeftHand = 4;
	int RightHand = 4;
	bool Leftd = false;
	bool Rightd = false;


	for (int i = 0; i < numbers.size(); i++)
	{
		int A = 0;
		if (KeyPed[numbers[i]] == 'L')
		{
			answer += KeyPed[numbers[i]];
			LeftHand = (numbers[i] + 2) / 3;
			Leftd = false;
			continue;
		}
		if (KeyPed[numbers[i]] == 'R') {
			answer += KeyPed[numbers[i]];
			RightHand = numbers[i] / 3;
			Rightd = false;
			continue;
		}
		else if (numbers[i] == 0) {
			A = 4;

		}
		else {
			A = (numbers[i] + 1) / 3;


		}
		int leftDistance = abs(A - LeftHand);
		int rightDistance = abs(A - RightHand);

		if (Leftd) leftDistance--;
		if (Rightd) rightDistance--;


		if (rightDistance == leftDistance) {
			if (hand == "right") {
				RightHand = A;
				answer += 'R';
				Rightd = true;

			}
			else {
				LeftHand = A;
				answer += 'L';
				Leftd = true;
			}
		}
		else if (leftDistance > rightDistance)
		{
			RightHand = A;
			answer += 'R';
			Rightd = true;
		}
		else {
			LeftHand = A;
			answer += 'L';
			Leftd = true;
		}


	}
}
//두개더 뽑아서 더하기
vector<int> toto(vector<int> numbers) {
		vector<int> answer;
		int PreviousNum = 0;
		for (int i = 0; i < numbers.size(); i++) {

			for (int j = i + 1; j < numbers.size(); j++) {
				answer.push_back(numbers[j] + numbers[i]);
			}
			PreviousNum = numbers[i];
		}

		sort(answer.begin(), answer.end());

		answer.erase(unique(answer.begin(), answer.end()), answer.end());
		return answer;
	}
//3진법 뒤집기
int eerht(int n) {
		int answer = 0;
		vector<int>as;
		while (n != 0)
		{
			as.push_back(n % 3);
			n /= 3;
		}
		for (int i = 0; i < as.size(); i++) {
			answer = answer * 3 + (as[i]);
		}
		return answer;
	}
//내적
int my_enemy(vector<int> a, vector<int> b) {
		int answer = 0;

		for (int i = 0; i < a.size(); i++) {
			answer += (a[i] * b[i]);
		}
		return answer;
	}
//이진 변환 반복하기 lv2
vector<int> changeChange(string s) {
		vector<int> answer = { 0,0 };
		while (s != "1")
		{
			answer[0]++;
			string s2 = s;
			s2.erase(remove(s2.begin(), s2.end(), '0'), s2.end());
			answer[1] += (s.length() - s2.length());
			s = "";
			int lenth = s2.length();
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
//신규 아이디 추천
string creatID(string new_id) {
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
//음양더하기
int umm(vector<int> absolutes, vector<bool> signs) {
		int answer = 0;
		for (int i = 0; i < absolutes.size(); i++) {
			signs[i] ? answer += absolutes[i] : answer -= absolutes[i];
		}

		return answer;
	}
//로또의 최고 순위와 최저 순위
vector<int> Lotto(vector<int> lottos, vector<int> win_nums) {
		vector<int> answer;
		int Rank[] = { 6,6,5,4,3,2,1 };
		int unrecognizableNum = 0; //0개수 만큼 더하거나 뺴줌
		int answerCount = 0;

		for (int i = 0; i < lottos.size(); i++) {

			if (lottos[i] == 0) {
				unrecognizableNum++; //0이면 continue
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
//약수의 개수와 덧셈
int uackgesu(int left, int right) {
		int answer = 0;
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
//숫자 문자열과 영단어
int onetwo(string s) {
		map<string, int> b;
		b.insert(pair<string, int>("zero", 0));
		b.insert(pair<string, int>("one", 1));
		b.insert(pair<string, int>("two", 2));
		b.insert(pair<string, int>("three", 3));
		b.insert(pair<string, int>("four", 4));
		b.insert(pair<string, int>("five", 5));
		b.insert(pair<string, int>("six", 6));
		b.insert(pair<string, int>("seven", 7));
		b.insert(pair<string, int>("eight", 8));
		b.insert(pair<string, int>("nine", 9));

		string stack;
		int answer = 0;
		for (int i = 0; i < s.size(); i++) {
			int a = 0;
			stack += s[i];
			if (b.find(stack) != b.end() && s.size() >= 2) {
				a = b[stack];
				answer *= 10;
				answer += a;
				stack = "";
			}
			if ('0' <= s[i] && s[i] <= '9')
			{
				answer *= 10;
				answer += s[i] - 48;
				stack = "";
			}



		}

		return answer;
	}
//부족한 금액 계산기
long long debt(int price, int money, int count)
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
//없는 숫자 더하기
int _404(vector<int> numbers) {
		int answer = 0;
		for (int i = 0; i < 10; i++)
		{
			for (auto a : numbers)
			{

				if (a == i)
				{
					goto gogogo;
				}
			}
			answer += i;
		gogogo:;
		}
		return answer;
	}
//최소 직사각형
int smallsqair(vector<vector<int>> sizes) {
		int W = 0;
		int H = 0;
		int answer;
		for (int i = 0; i < sizes.size(); i++) {
			if (sizes[i][0] > sizes[i][1]) {
				int temp = sizes[i][1]1;
				sizes[i][1] = sizes[i][0];
				sizes[i][0] = temp;
			}

			if (sizes[i][0] > W) {
				W = sizes[i][0];
			}

			if (sizes[i][1] > H) {
				H = sizes[i][1];
			}
		}
		answer = H * W;
		return answer;
	}
//나머지가 1이되는수 찾기
int _5432(int n) {
		int answer = 0;
		for (int i = 1; i < n + 1; i++) {
			if (n % i == 1) { answer = i; break; }
		}
		return answer;
	}
//신고 결과 받기
vector<int> repot(vector<string> id_list, vector<string> report, int k) {
		vector<int> answer;
		vector<int> Reported_person; //신고당한 횟수
		vector<bool> Reported_persons; //신고 당한사람중 정지인사람
		vector<vector<bool>> ReportCount;//  신고한 사람 - 신고당한사람들
		map<string, int> ID; //사람 이름당 번호

		for (int i = 0; i < id_list.size(); i++) {

			ID.insert(make_pair(id_list[i], i)); //map에 넣어주고
			ReportCount.push_back({}); // 초기화
			Reported_person.push_back({}); // 초기화
			Reported_persons.push_back({}); // 초기화
			answer.push_back({}); // 초기화

			for (int j = 0; j < id_list.size(); j++) {
				ReportCount[i].push_back(false); //fals로 넣어주고
			}

		}

		for (int i = 0; i < report.size(); i++) {

			string reprotMessage; //현재 이름
			string Repoter1;
			for (int j = 0; j < report[i].size(); j++) {
				if (report[i][j] == ' ') { // 스페이스바 - 구별
					Repoter1 = reprotMessage; //신고한사람 저장
					reprotMessage = ""; //초기화
					continue;
				}
				reprotMessage += report[i][j];
			}
			// Repoter1 신고한사람  reportMessage //신고할 닉네임

			if (reprotMessage == Repoter1) {
				continue; //본인이면 무시
			}

			if (ReportCount[ID.find(Repoter1)->second][ID.find(reprotMessage)->second] == false)
			{
				ReportCount[ID.find(Repoter1)->second][ID.find(reprotMessage)->second] = true;
				Reported_person[ID.find(reprotMessage)->second]++;

				if (Reported_person[ID.find(reprotMessage)->second] >= k)
				{
					Reported_persons[ID.find(reprotMessage)->second] = true; //k보다 큰게 복수로 들어감
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
//성격유형검사
string MBTI(vector<string> survey, vector<int> choices) {

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
//붕대 감기
int bandage(vector<int> bandage, int health, vector<vector<int>> attacks) {


		unordered_map<int, int> monsters;
		int answer = 1;
		int continuous = 0;
		int max_health = health;
		int AttacksCount = attacks.size();

		for (auto attack : attacks) {
			monsters[attack[0]] = attack[1];

		}

		while (health >= 0 && AttacksCount != 0) {
			if (monsters.find(answer) != monsters.end()) {
				continuous = 0;
				health -= monsters[answer];
				AttacksCount--;
			}
			else {
				continuous++;

				health += bandage[1];
				if (continuous == bandage[0]) {
					continuous = 0;
					health += bandage[2];
				}
				if (max_health < health) health = max_health;

			}
			answer++;

		}




		return health <= 0 ? -1 : health;
		return answer;
	}
//석유 시추
static int const nextland[4][2]{ {0,1}, {1,0}, {-1,0}, {0,-1} };
void find_oil(vector<vector<int>>& land, int x, int y, int& oil_count, unordered_map<int, int>& oil_monny) {
		queue<tuple<int, int>> nextxy;
		nextxy.push(make_tuple(x, y));
		land[x][y] = oil_count;
		oil_monny[oil_count]++;
		while (nextxy.size() != 0)
		{


			tuple<int, int> nxy = nextxy.front();
			int xy[2]{ get<0>(nxy),get<1>(nxy) };
			nextxy.pop();


			int x, y = 0;
			for (auto arrow : nextland) {
				y = arrow[1] + xy[1];
				x = arrow[0] + xy[0];
				if (x >= 0 && x < land.size() && y >= 0 && y < land[0].size() && land[x][y] == 1) {
					land[x][y] = oil_count;
					oil_monny[oil_count]++;
					nextxy.push(make_tuple(x, y));
				}
			}
		}
		oil_count++;
	}
int sicu(vector<vector<int>> land) {
		int answer = 0;
		int oil_count = 2;
		unordered_map<int, int> oil_monny;

		for (int i = 0; i < land.size(); i++) {
			for (int j = 0; j < land[i].size(); j++) {
				if (land[i][j] == 1) {
					find_oil(land, i, j, oil_count, oil_monny);
				}
			}
		}


		for (int i = 0; i < land[0].size(); i++) {
			vector<bool>c(oil_count - 2);
			int b = 0;
			for (int j = 0; j < land.size(); j++) {
				if (land[j][i] > 1 && (c[land[j][i] - 2] == false)) {
					c[land[j][i] - 2] = true;
					b += oil_monny[land[j][i]];
				}
			}
			if (answer < b) {
				answer = b;
			}
		}

		return answer;
	}
//달리기 경주
vector<string> runing_inthe(vector<string> players, vector<string> callings) {


		std::unordered_map<string, int> PlayersMap;
		for (int i = 0; i < players.size(); i++)
		{
			PlayersMap.insert(make_pair(players[i], i));
		}


		for (auto name : callings) {
			int a = PlayersMap[name]--;
			auto p = players[a];
			players[a] = players[a - 1];
			players[a - 1] = p;
			PlayersMap[players[a]]++;

		}
		return players;
	}
//바탕화면 정리
vector<int> my_room(vector<string> wallpaper) {
		vector<int> answer = { (int)(wallpaper.size() - 1),(int)(wallpaper[0].size() - 1),0,0 };

		for (int i = 0; i < wallpaper.size(); i++) {
			for (int j = 0; j < wallpaper[0].size(); j++) {
				if (wallpaper[i][j] == '#') {
					if (answer[0] > i) answer[0] = i;
					if (answer[1] > j) answer[1] = j;
					if (answer[2] < i + 1) answer[2] = i + 1;
					if (answer[3] < j + 1) answer[3] = j + 1;
				}
			}
		}
		return answer;
	}
#pragma endregion
	
#pragma region 백준

// 4659 실버 5 비밀번호 발음하기
int bi__mill__bunho()
{
	string str = "";
	vector<string> strings = {};
	cin >> str;
	while (str != "end")
	{
		bool IsAcceptable = true;
		int moum = 0, conMoum = 0, conJar = 0, samechar = 0;
		char afterstr = ' ';
		for (auto A : str) {
			if (A == 'a' || A == 'e' || A == 'i' || A == 'o' || A == 'u')
			{
				moum++;
				conJar = 0;
				conMoum++;
			}
			else {
				conMoum = 0;
				conJar++;
			}
			if (A == afterstr) {
				if (A != 'e' && A != 'o') {
					IsAcceptable = false;
				}
			}
			else afterstr = A;
			if (conMoum >= 3 || conJar >= 3)IsAcceptable = false;
			if (IsAcceptable == false) break;
		}
		if (IsAcceptable && moum >= 1)
			strings.push_back('<' + str + '>' + " is acceptable.");
		else
			strings.push_back('<' + str + '>' + " is not acceptable.");
		cin >> str;
	}
	for (auto st : strings) {
		cout << st << endl;
	}
}
//1026 실버 4 보물
int Imfind_onepice() {
	int a = 0;
	int answer = 0;
	vector<vector<int>> A;
	A = { {} ,{} };
	cin >> a;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < a; j++) {
			int b = 0;
			cin >> b;
			A[i].push_back(b);
		}
	}

	sort(A[0].begin(), A[0].end(), less<>());
	sort(A[1].begin(), A[1].end(), greater<>());
	for (int i = 0; i < a; i++) {
		answer += (A[0][i] * A[1][i]);
	}


	cout << answer;
	return 0;
}
//1463 실버 3 1로만들기
int _array[1000001] = { 0 };
void Fcounter(int a, int Max, int count) {
	if ((_array[a] == 0 || _array[Max] > count) && (a == Max)) {
		_array[Max] = count;
	}
	if ((_array[a] != 0 && _array[a] < count) || (a <= Max))return;
	_array[a] = count;
	count++;

	if (a % 3 == 0) {
		Fcounter(a / 3, Max, count);
	}
	if (a % 2 == 0) {
		Fcounter((a / 2), Max, count);
	}
	if (!((a % 2 == 0) && (a % 3 == 0)))
	{
		Fcounter(a - 1, Max, count);
	}
}
//1254 실버 2 팰린드롬 만들기
int pandrom() {
	string S = "";
	int sameNuber = 0;
	cin >> S;
	for (long int i = floor((S.size() - 1) / 2); i < (int)S.size() - 1; i++) {

		if (S.size() == 2) {
			if (S[i] == S[i + 1]) sameNuber = 2;
			break;
		}
		if (S[i - 1] == S[i + 1]) {
			for (long int j = 1; j < (int)S.size() - i; j++) {
				if (i - j < 0 || !(S[i - j] == S[i + j]) || S.size() - j == 0) {
					break;
				}
				if (i + j == (int)S.size() - 1) {
					sameNuber = floor(S.size() - ((S.size() - i - 1) * 2)) + S.size() - 1;
				}
			}
		}
		if (sameNuber != 0) break;
		if (S[i] == S[i + 1]) {
			for (long int j = 1; j < (int)S.size() - i; j++) {
				if (i + 1 - j < 0 || !(S[i - j + 1] == S[i + j]) || S.size() - j == 0) {
					break;
				}
				if (i + j == (int)S.size() - 1) {
					int a = floor(S.size() - ((S.size() - i - 1) * 2)) + S.size();
					sameNuber = sameNuber < a ? a : sameNuber;
				}
			}
		}
		if (sameNuber != 0) break;
	}
	if (sameNuber == 0)  sameNuber = (S.size() * 2) - 1;
	std::cout << sameNuber;
	return 0;
}
//12915 실버 1 대회 개최
int lol_Guckzun() {
	int E, EM, M, MH, H, answer;
	E = EM = M = MH = H = answer = 0;
	scanf("%d %d %d %d %d", &E, &EM, &M, &MH, &H);
	while (true)
	{
		if (E == 0)EM--; else E--;
		if (H == 0)MH--; else H--;
		if (M == 0) (EM >= MH) ? EM-- : MH--; else  M--;
		if (EM < 0 || MH < 0) break;
		answer++;
	}
	printf("%d", answer);
}
//1068 트리 골드5
int treee() {
	unordered_map<int, vector<int>> trees;
	int answer = 0;
	queue<int>sercheNum;
	int size, delnum;
	cin >> size;
	int rootnode = -1;
	for (int i = -1; i < size; i++) trees[i] = {};
	for (int i = 0; i < size; i++) {
		int num;
		cin >> num;
		trees[num].push_back(i);
	}
	cin >> delnum;
	sercheNum.push(-1);
	trees.erase(delnum);
	while (!sercheNum.empty())
	{
		int serch = sercheNum.front();
		if (trees.find(serch) == trees.end())
		{
			sercheNum.pop(); continue;
		}
		if (!trees[serch].empty()) {
			if (trees[serch].size() == 1) {
				if (trees.find(trees[serch][0]) == trees.end() && serch != rootnode) {
					answer++;
					sercheNum.pop();
					continue;
				}
			}
			for (int i = 0; i < trees[serch].size(); i++) {
				sercheNum.push(trees[serch][i]);
			}
		}
		else answer++;
		sercheNum.pop();
	}
	cout << answer;
	return 0;
}
//1240골드5 노드사이의 거리
#define AtoB pair<int,int>
unordered_map<int, vector<AtoB>> tree;
int FinderNum(int startNode, int num, int distance, int backNum = 0) {

	if (tree[startNode].empty())return 0;

	for (int i = 0; i < tree[startNode].size(); i++) {
		if (tree[startNode][i].first == num) {
			return distance + tree[startNode][i].second;
		}
		else if (tree[startNode][i].first != backNum) {
			int dis = FinderNum(tree[startNode][i].first, num, (distance + tree[startNode][i].second), startNode);
			if (dis > 0)return dis;
		}
	}
	return 0;
}
int nodetonode() {
	int treeSize = 0, searchCount = 0;
	cin >> treeSize >> searchCount;
	for (int i = 0; i < treeSize - 1; i++) {
		int a = 0, b = 0, dis = 0;
		cin >> a >> b >> dis;
		if (tree[a].empty())
			tree[a] = { {b,dis} };
		else tree[a].push_back({ b, dis });

		if (tree[b].empty())
			tree[b] = { {a,dis} };
		else tree[b].push_back({ a, dis });
	}
	vector<int> k = {};
	for (int i = 0; i < searchCount; i++) {
		int a = 0, b = 0, distance = 0;
		cin >> a >> b;
		distance = FinderNum(a, b, distance);
		k.push_back(distance);
	}
	for (auto a : k) {
		cout << a << endl;
	}
	return 0;
}
//7569 토마토
vector<XYZ> nonfire;
const XYZ MoverDirection[4] = { {1,0} ,{-1,0} ,{0,-1} ,{0,1} };
vector<vector<int>> vec;
int N = 0, H = 0;
vector<XYZ> findNextTomato(vector<XYZ> _xyz) {

	vector<XYZ> firebe = {};
	for (auto a : _xyz) {
		for (auto Dir : MoverDirection) {
			int  xyz2[2] = { get<0>(a) + get<0>(Dir),get<1>(a) + get<1>(Dir) };

			if (!(get<0>(a) + get<0>(Dir) < N && get<0>(a) + get<0>(Dir) >= 0 &&
				get<1>(a) + get<1>(Dir) < H && get<1>(a) + get<1>(Dir) >= 0)) {
				continue;
			}

			if (vec[xyz2[0]][xyz2[1]] == 0) {
				firebe.push_back(XYZ(xyz2[0], xyz2[1]));
				vec[xyz2[0]][xyz2[1]] = 1;
			}
		}
	}
	return firebe;
}
int tomato_tomato() {


	cin >> H >> N;

	vector<XYZ> fire;
	int answer = 0;
	for (int i = 0; i < N; i++) {
		vec.push_back({});
		for (int j = 0; j < H; j++)
		{
			int a;
			cin >> a;
			vec[i].push_back(a);

			if (a == 1)
			{
				fire.push_back(XYZ(i, j));
			}
			if (a == 0) {
				nonfire.push_back(XYZ(i, j));
			}

		}
	}

	while (true)
	{
		if (fire.size() <= 0)
			break;
		fire = findNextTomato(fire);

		//cout << endl;

		//for (auto x : vec) {
		//	for (auto y : x) {
		//		cout << y;
		//		cout << " ";
		//	}
		//	cout << endl;

		//}

		answer++;
	}

	for (auto a : nonfire) {
		if (vec[get<0>(a)][get<1>(a)] == 0)answer = 0;
	}
	cout << (answer - 1);

}
//1929 소수 구하기 실버3
int sosu() {
	unordered_map<int, bool> b{ {1,true}, {0,true}, };
	int a = 0, c = 0;
	scanf("%d %d", &a, &c);

	for (int i = 2; i <= c; i++) {
		if (b[i] == true)  continue;
		for (int j = i + i; j <= c; j += i) {
			b[j] = true;
		}
	}
	for (int i = a; i <= c; i++) {
		if (b[i] == false) printf("%d \n", i);
	}
}
//1018 실버4 체스판 다시칠하기
int msize = 4;
int Rechess(int w, int h, vector<vector<bool>>& map) {

	int Lower = 65;
	int ms = 0;
	//상하좌우 8칸기준 절반씩 최소 공간확보                
	for (int i = msize; i < w - msize + 1; i++) {
		for (int j = msize; j < h - msize + 1; j++) {
			//홀짝 홀짝 홀홀짝짞 계산
			for (int b = 0; b < 2; b++) {
				int Lowers = 0;

				for (int k = i - msize; k < i + msize; k++) {
					for (int n = j - msize; n < j + msize; n++) {
						//cout << (map[k][n] ? "■" : "□"); // 자른거 검토
						//cout << (((n + k) + b)%2); 홀짝 만들기
						//짝수 홀수 검토
						if (map[k][n] == (((n + k) + b) % 2))Lowers++;
					}
					//cout << endl;

				}
				//cout << Lowers;
				Lower = Lowers < Lower ? Lowers : Lower;

				//	cout << endl;

			}

		}
	}

	return Lower;
}
int new_Chess() {
	//int** d = (int**)malloc(sizeof(int*) * 50);
	int a = 0, b = 0;
	string s;
	vector<vector<bool>> d;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		d.push_back({});
		cin >> s;
		for (char var : s)
		{
			d[i].push_back(var == 'W' ? true : false);
		}
	}

	cout << Rechess(a, b, d);

}
//9012 괄호 실버4
bool garho(string s) {
	int garho = 0;
	bool answer = true;
	for (auto i : s) {
		if (i == '(')garho++;
		else garho--;

		if (garho < 0) {
			answer = false;
		}

	}

	if (garho != 0) answer = false;
	return answer;
}
int Garho_main() {

	int a = 0;
	string s = ")()(";
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> s;
		cout << (garho(s) ? "YES\n" : "NO\n");

	}

}
//4485 녹색옷 입은 애가 젤다지? 골드4
static int const nextlands[4][2]{ {0,1}, {1,0}, {-1,0}, {0,-1} };
int find_zelda(vector<vector<int>>& land, vector<vector<int>>& sland) {
	priority_queue<pair< int, pair<int, int>>> nextxy;
	nextxy.push(make_pair(sland[0][0], make_pair(0, 0)));

	sland[0][0] = land[0][0];

	while (nextxy.size() != 0)
	{

		pair<int, pair<int, int>> nxy = nextxy.top();
		int xy[2]{ (nxy.second.first),(nxy.second.second) };
		nextxy.pop();
		int testn = 0;
		int x, y = 0;
		for (auto arrow : nextlands) {
			y = arrow[1] + xy[1];
			x = arrow[0] + xy[0];

			if (x >= 0 && x < land.size() && y >= 0 && y < land[0].size()) {

				if (sland[x][y] == INT16_MAX && sland[x][y] > -nxy.first + land[x][y]) {
					sland[x][y] = sland[xy[0]][xy[1]] + land[x][y];

					nextxy.push(make_pair(-sland[x][y], make_pair(x, y)));
				}
				if (x == sland.size() - 1 && y == sland.size() - 1)return sland[sland.size() - 1][sland.size() - 1];
			}
		}

	}
	return sland[sland.size() - 1][sland.size() - 1];

}
int find_zelda_Main() {
	int num = 0;
	int m = 0;
	while (true)
	{
		num++;
		vector<vector<int>> map;
		vector<vector<int>> smap;
		cin >> m;
		if (m == 0)break;
		int s;
		for (int i = 0; i < m; i++)
		{
			map.push_back({});
			smap.push_back({});
			for (int j = 0; j < m; j++) {
				cin >> s;
				map[i].push_back(s);
				smap[i].push_back(INT16_MAX);
			}
		}

		cout << "Problem " << num << ": " << find_zelda(map, smap) << "\n";
	}

}
//5719 거의 최단경로 플레티넘5
#define cost 0
#define Nextroad 1
#define MM_Num  9999999
const auto& mt = make_tuple(MM_Num, MM_Num);
void Distory(unordered_map<int, vector<tuple<int, int>>>& Umap, vector< queue<int>>& nodeGansun, int end) {

	while (!nodeGansun[end].empty())
	{
		int num = nodeGansun[end].front();
		nodeGansun[end].pop();
		for (auto& um : Umap[num]) {
			if (get<1>(um) == end) {
				um = make_tuple(MM_Num, MM_Num);
				Distory(Umap, nodeGansun, num);
			}
		}
	}
}
void find_FIRST_DS(unordered_map<int, vector<tuple<int, int>>>& Umap, int start, int end, int nodesize) {

	priority_queue<tuple<int, int, int>> nextxy;
	// 거리 위치 현재까지 오는 간선
	vector<int> noodBool(nodesize + 1, MM_Num);
	vector< queue<int>>nodeGansun(nodesize + 1, queue<int>());
	noodBool[start] = MM_Num;

	tuple<int, int, int> nxy;
	int d = 0, arrowRoad = 0, arrowcost = 0;
	nextxy.emplace(make_tuple(0, start, start));

	int first = MM_Num;
	while (!nextxy.empty())
	{

		nxy = nextxy.top();
		nextxy.pop();
		arrowcost = -get<0>(nxy);
		arrowRoad = get<1>(nxy);
		if (get<1>(nxy) == end) {
			if (first == get<0>(nxy)) {
				first = get<0>(nxy);
				break;
			}
		}

		if (noodBool[arrowRoad] == MM_Num || noodBool[arrowRoad] > (arrowcost)) {

			noodBool[arrowRoad] = arrowcost;

			nodeGansun[arrowRoad] = queue<int>();
			nodeGansun[arrowRoad].push(get<2>(nxy));

		}
		else if (noodBool[arrowRoad] == (arrowcost))
		{
			nodeGansun[arrowRoad].push(get<2>(nxy));
			continue;
		}
		else  continue;

		//앞이 점수 뒤가 연결된 리스트



		d = get<0>(nxy);
		for (int i = 0; i < Umap[get<Nextroad>(nxy)].size(); ++i) {

			tuple<int, int> arrow = Umap[get<1>(nxy)][i];
			arrowRoad = get<1>(arrow);
			arrowcost = get<0>(arrow);
			if (noodBool[arrowRoad] == MM_Num || noodBool[arrowRoad] > (arrowcost + -(d))) {
				nextxy.emplace(make_tuple(-(arrowcost + -(d)), get<1>(arrow), get<1>(nxy)));

			}


		}
	}
	while (!nextxy.empty()) {
		auto b = nextxy.top();
		nextxy.pop();
		if (get<1>(b) == end && get<0>(b) == first) {
			nodeGansun[end].push(get<2>(b));
		}
	}

	Distory(Umap, nodeGansun, end);


	return;
}
int find_second_DS(unordered_map<int, vector<tuple<int, int>>>& Umap, int start, int end, int nodesize) {
	priority_queue<tuple< int, int>> nextxy;
	vector<bool> noodBool(nodesize + 1, false);
	tuple<int, int> nxy;
	nextxy.emplace(make_tuple(0, start));
	bool lastnode = false;
	noodBool[start] = true;
	while (!nextxy.empty())
	{
		nxy = nextxy.top();
		nextxy.pop();
		noodBool[get<1>(nxy)] = true;

		if (get<1>(nxy) == end) {
			return  (-get<0>(nxy));
		}
		for (const auto& arrow : (Umap[get<1>(nxy)])) {
			if (get<1>(arrow) == MM_Num)continue;
			if (noodBool[get<1>(arrow)]) {
				continue;
			}
			nextxy.emplace(make_tuple(-(get<0>(arrow) + -(get<0>(nxy))), get<1>(arrow)));
		}
	}
	return (-1);
}
int find_second_DS_main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(NULL);
	int NodeSize = 0, NodeLoadSize = 0, Start = 0, end = 0;
	int node = 0, Xnode = 0, Dis = 0;
	unordered_map<int, vector<tuple<int, int>>> Umap;
	vector<int> answer;
	while (true)
	{
		cin >> NodeSize >> NodeLoadSize;
		if (NodeSize == 0 && NodeLoadSize == 0)
			break;
		cin >> Start >> end;


		Umap.clear();
		for (int i = 0; i < NodeLoadSize; i++)
		{
			cin >> node >> Xnode >> Dis;
			Umap[node].emplace_back(make_tuple(Dis, Xnode));
		}

		find_FIRST_DS(Umap, Start, end, NodeSize);
		answer.emplace_back(find_second_DS(Umap, Start, end, NodeSize));
	}
	for (const auto& an : answer) {
		printf("%d\n", an);
	}
	return 0;
}
//5639 이진트리 골드 5
struct node
{
public:
	int key;
	node* LeftNode = nullptr;
	node* RightNode = nullptr;
};
class EzinTree {
public:
	node RootNode;

	void AllGungisunhe(node& nextn);

	void AddKey(int key, node& n);
};
void EzinTree::AllGungisunhe(node& nextn)
{
	if (nextn.LeftNode != nullptr) {
		AllGungisunhe(*nextn.LeftNode);
	}
	if (nextn.RightNode != nullptr) {
		AllGungisunhe(*nextn.RightNode);
	}
	cout << nextn.key << "\n";
}
void EzinTree::AddKey(int key, node& n)
{
	if (n.key == key)return;
	else if (n.key > key) {
		if (n.LeftNode == nullptr) {
			node* Newn = new node();
			Newn->key = key;
			n.LeftNode = Newn;
		}
		else
		{
			AddKey(key, *n.LeftNode);
		}

	}
	else if (n.key < key) {
		if (n.RightNode == nullptr) {
			node* Newn = new node();
			Newn->key = key;
			n.RightNode = Newn;
		}
		else {
			AddKey(key, *n.RightNode);
		}
	}
}
int EzinTree_main() {
	EzinTree et;

	unsigned int arr[10001]; unsigned int size = 0;
	while (1)
	{
		if (scanf(" %u", &arr[size]) == EOF) { break; }
		if (size == 0) {
			node n;
			n.key = arr[size];
			et.RootNode = n;
		}
		if (arr[size] == 0)break;
		et.AddKey(arr[size], et.RootNode);


		size++;
	}
	et.AllGungisunhe(et.RootNode);
	return 0;

}
//18111 마인크래프트 실버 2
void MinecraftCreatHouse() {
	int N = 0, M = 0, B = 0;
	int map[501][501] = { 0, };
	cin >> N >> M >> B;
	int k = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int a = 0;
			cin >> a;
			map[i][j] = a;
			if (a > k && 256 >= a) k = a;
		}
	}
	int Low = 2147483647;
	int Hi = 0;
	for (int L = k; L >= 0; L--) {
		int num = 0;
		int block = B;
		bool brea = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == L)continue;

				if (map[i][j] > L) {
					num += (map[i][j] - L) * 2;
					block += (map[i][j] - L);
				}
				else if (map[i][j] < L) {
					num += (L - map[i][j]);
					block -= (L - map[i][j]);
				}
			}
		}
		if (block < 0) { continue; }
		if (Low > num) {
			Low = num;
			Hi = L;
		}
		if (Low == num) {
			if (Hi < L)
				Hi = L;
		}

	}
	cout << Low << " " << Hi;
}



#pragma endregion

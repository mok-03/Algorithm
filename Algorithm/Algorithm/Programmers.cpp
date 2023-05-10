
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
#include "Programmers.h"
#include <functional>
using namespace std;
//퀵정렬
vector<int> QuickSortting(vector<int> a)
{
	/*
	#include <vector>

	// Function prototype
	std::vector<int> QuickSortting(std::vector<int> a);

	int main() {
	  // Create a vector of integers
	  std::vector<int> a = {4, 2, 7, 5, 1, 6, 8, 3};

	  // Sort the vector using QuickSort
	  std::vector<int> sorted = QuickSortting(a);

	  // Print the sorted vector
	  for (int i = 0; i < sorted.size(); i++) {
		std::cout << sorted[i] << " ";
	  }
	  std::cout << std::endl;

	  return 0;
	}

	std::vector<int> QuickSortting(std::vector<int> a) {
	  // Base case: return if the vector contains only one element
	  if (a.size() == 1) return a;

	  // Get the middle element of the vector
	  int half = a.size() / 2;
	  int ahalf = a[half];

	  // Initialize vectors for left and right subarrays
	  std::vector<int> Left, Right;

	  // Partition the vector into left and right subarrays
	  for (int i = 0; i < a.size(); i++) {
		if (i == half) continue; // Skip the middle element
		if (a[i] < ahalf) {
		  Left.push_back(a[i]);
		}
		else {
		  Right.push_back(a[i]);
		}
	  }

	  // Recursively sort the left and right subarrays
	  if (Left.size() != 0) Left = QuickSortting(Left);
	  if (Right.size() != 0) Right = QuickSortting(Right);

	  // Concatenate the left subarray, middle element, and right subarray
	  std::vector<int> result;
	  result.insert(result.end(), Left.begin(), Left.end());
	  result.push_back(ahalf);
	  result.insert(result.end(), Right.begin(), Right.end());

	  return result;
	}
	ai 피드백 에전에 본거 같은코드임 코드가 훨씬 깔끔함
	*/


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
//		cout << "생성자" << endl;
//	}
//	virtual ~CTest() {
//		cout << "소멸자" << endl;
//	}
//	//CTest *pTest = new CTest[10];
//
//	//delete[] pTest; //소멸자가 없으면 [] 가없어도 정상작동 된다.
//};


/*

 1. 어피치 n발을 다쏜후 라이언 화살 n발 쏨

 2. 점수를 계산합니다.
	2-1. 과녁판은 안쪽부터 외각으로 10.9.8...
	2-2. 만약, k점을 어피치가 a발 맞혔고 라이언이 b발을 맞혔을 경우 더많은 화살을  k 점에 맞힌 선수가 k점을 가저갑니다.
			  ㄴ 같은점수에 더많이 맞힌사람이 들고감
				ㄴ a=b 일경우 어피치가 k점을 가져간다. k점에 많이 맞혀둬 k점만 들고간다 k가 10 일때 k를 10번 맞혀도 10점

	2-3. 모든 과녁 점수에 대하여 각선수의 점수를 계산한다

3. 최종점수가 더 높은 선수를 우승자로 결정합니다, 두명이 같은경우 어피치를 우승자로 함

4. 라이언이 우승할수 없는경우 -1 리턴 "무조건" 지거나 비기는경우


현재 상황은 어피치가 화살 n 발을 다쏜후이고 라이언이 화살을 쏠차례이다.
라이언은 어피치를 가장 큰점수 차이로 이기기 위해서 n발의 화살을 어떤 과녁 점수에 맞혀야 하는지 구하려한다.

화살의 개수를 담은 자연수 n

어피치가 맞춘 과녁개수 10 -> 0  info


!! 가장 큰점수로 이겨야함

!!! 가장 큰점수로 이기는 방법이 여러
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


int solution(int n, int k, vector<int> enemy) {
	int answer = 0;
	vector<int> BigerStage{}; //bigerstage 는 stage를 그냥 n으로 돌면서 큰값을들 오름차순으로 넣기 
	// k개수를 계산하기 시작하면 k값만큼 biger 
//1 7 3 5  4 5 5 B[7 5 3]  3 5 5 , n = 2
//1 7 5 3  4 5 5 B[7 5 3]  3 5 5 , n = 2 


//넘어가는조건
/*
1. 일단 자신n보다 enemy[i] 값이 더크면 무조건 스킵
2. 자신보다 큰데 k가 여분이 없으면 거기서 스탑
3. 자신이 끝까지 도착했는데 (n을 다소모했는데) k가 남을시
4. 자신의 bigerstage  에 자신이 지나왔던 가장큰 숫자를 k만큼 추가하고 추가한 숫자 종합 n 추가
5. if n만큼 가는데 bigerstage 값중 제일작은값보다 큰값이 (나왔을경우 제일작은값 - 현재 가진 n값)
 if  (7 15 5) 바로 다음값이 중 20을만날경우
 현재 포인트는 27이지만 하나라도 뺄경우 20까지 올수가 없기때문에 크더라도 뭘할수가 없음 r그냥 계산
 하지만
 그럼 그때그때 해줘야겠네
 에메한경우를 위해 n이 6 이고 enum[] 이 7 인경우 큰거 하나만 쓰고 다시 비교했을때 가능하기도 함
 내부에 k를 안쓰고 계산 한것중 가장큰값 3 8 2  , n 6  [ 7 1]  지나온값 ,n값, 남은 값 인경우
		7을 무시하는것보다  k가아닌 자신의 포인트를 사용한 8을제외하고 계산하면 1이 더남음


	조건
	1. 직진하다 n보다 큰수를 만남
	2. 자신이 지나온 길에 있는 숫자들 보다 큼 -> k사용
	3. k를 사용하여 넘어온 수는 아에 k를-해준뒤 enum[i] = 0 을 해줌 비교못하게
	4.

*/
	for (int i = 0; i < enemy.size(); i++) {
		if (enemy[i] <= n) { // n 보다 스테이지가 작을떼
			n -= enemy[i];
			if (BigerStage.size() == 0) {

				BigerStage.push_back(enemy[i]);
			}
			else if (BigerStage[0] < enemy[i]) {
				BigerStage.insert(BigerStage.begin(), enemy[i]);
			}
			else {
				for (int j = 0; j < BigerStage.size(); j++) {
					if (BigerStage[j] < enemy[i] && BigerStage[j] != 0) {
						BigerStage.insert(BigerStage.begin() + j - 1, enemy[i]);
						break;
					}
				}
				BigerStage.push_back(enemy[i]);

			}
			answer++;
		}
		else if (k > 0) { // 커서 이기지 못할때

			// 자신이 직접 클리어한 스테이지 중에 enemy[i] 스테이지 보다 큰 숫자가 있는지 확인
			// 더큰수가 있으면 그거 스킵한뒤 다음스테이지 현재 점수 깍고 진행
			for (int j = 0; j < BigerStage.size(); j++) {
				if (BigerStage[j] == 0) continue;

				if (BigerStage[j] > enemy[i]) {
					n += BigerStage[j] - enemy[j];

					BigerStage[j] = 0;
					break;
				}
			}
			k--;
			answer++;
		} //작지만 k가 없을때
		else {
			break;
		}
	}


	//현재 그걸로 갈수 있는 길이중 [oooooxxx] o만큼 갈수 있다면 그사이에 있는 가장큰 값을 k개 제외
	// 그러면 x값에서 제외한숫자를 n에 더한뒤 다시 계산 그러면 계산한 숫자만큼 +
	//주의할점 무조건 크다고 제외하면 손해봄(도착을못해서) , 그 스테이지를 도착하더라도 내 n값이 enemy[i] 값보다 작으면 그 스테이지는
	//값을 안쳐줌

	return answer;
}
//마지막에 bool과 bigerNumber와 smallNumber로 코드 정리
int EraToseTenes_chea(int n);
class MyClass : public  A
{
public:
	static vector<void* (*)(void*)> vec;
	int bc = 10;
	void Sele() {
		cout << bc;
	}



};
class Player
{

public:
	Player(int c) : b(c) { cout << a << endl; };
	int b = 21;
	void playerMove();
	void playerIdle();
private:
	int a = 10;

};
void Player::playerMove()
{
	this->a += this->b;
}
void Player::playerIdle() {
	cout << a << endl;
}
//template <typename T>
class Deleg {
public:
	//void (T::* funcs)(T);
	std::vector<std::function<void()>> Deleg;
};
enum PlayerState
{
	Move,
	Idel,
	Skill,
	GenderCount
};

class BTree {
	int Number_L;
	int Number_R;


};

vector<int> hackyoul(long long k, int i, vector<int> num) {

	int b = i * (i - 1);
	if (i < k && b >k) {
		num.push_back(k % i);
		return hackyoul(k, i + 1, num);
	}
	return num;
}


//
//int mAPsolution(vector<vector<int> > map, int PlayerPos[2], int CountTile)
//{
//
//	
//
//	if (PlayerPos[0] == map.size() - 1 && PlayerPos[1] == map[0].size() - 1) {
//
//		return CountTile + 1;
//	}
//	while (true)
//	{
//		if (CountTile >= smallerD)
//			return-1;
//		vector<int> Rood[2] = {{},{}};
//
//		for (int i = 0; i < 4; i++) {
//
//			int exPlayerPos[2] = { PlayerPos[0] + (maps[i][0]), (PlayerPos[1]) + maps[i][1] };
//			if ((0 <= (exPlayerPos[0]) && 0 <= (exPlayerPos[1])) &&
//				(map.size() > (exPlayerPos[0]) && map[0].size() > (exPlayerPos[1]))
//
//				) {
//				if (map[(exPlayerPos[0])][(exPlayerPos[1])])
//				{
//				
//					Rood[0].push_back(exPlayerPos[0]);
//					Rood[1].push_back(exPlayerPos[1]);
//				}
//			}
//
//		}
//		if (Rood[0].size() > 1) {
//
//			vector<int> Rvalue = {};
//
//			string SRood = to_string((PlayerPos[0])) + to_string((PlayerPos[1]));
//			if ((Croosmap[SRood] == 0 || Croosmap[SRood] > CountTile)) {
//				Croosmap[SRood] = CountTile;
//			}
//			else {
//				return-1;
//			}
//			map[(PlayerPos[0])][(PlayerPos[1])] = 0;
//			CountTile++;
//
//			for (int i = 0; i < Rood[0].size(); i++) {
//				int RoodPos[2] = { Rood[0][i],Rood[1][i] };
//				int returnValue = mAPsolution(map, RoodPos, CountTile);
//
//				if (returnValue > 0) {
//					Rvalue.push_back(returnValue);
//				}
//			}
//
//			if (Rvalue.size() > 0) {
//				int smaller = Rvalue[0];
//				for (int values : Rvalue) {
//					if (smaller > values) {
//						smaller = values;
//					}
//				}
//				smallerD = smaller;
//				return smaller;
//			}
//			return -1;
//		}
//		else if (Rood[0].size() == 1) {
//
//			map[(PlayerPos[0])][(PlayerPos[1])] = 0;
//			int RoodPos[2] = { Rood[0][0],Rood[1][0] };
//			PlayerPos = (RoodPos);
//			CountTile++;
//
//			if (PlayerPos[0] == map.size() - 1 && PlayerPos[1] == map[0].size() - 1) {
//
//				cout << CountTile << endl;
//				return CountTile + 1;
//			}
//		}
//		else {
//
//			if (PlayerPos[0] == map.size() - 1 && PlayerPos[1] == map[0].size() - 1) {
//
//				cout << CountTile << endl;
//				return CountTile + 1;
//			}
//			return -1;
//		}
//
//
//
//
//
//
//	}
//
//
//}
#include <queue>;
class Rload {
public:
	int value;
	int x;
	int y;
};
static const int mapMove[4][2] = { {0,1},{1,0},{0,-1} ,{-1,0} };
queue<Rload> CroosRload = {};
int Rood[2][4] = { {0,0,0,0},{0,0,0,0} };
#pragma region DethCode 

int mAPsolution(vector<vector<int> >& map, int PlayerPosx, int PlayerPosy, int CountTile)
{

	int roodCount = 0;
	if (PlayerPosx == map.size() - 1 && PlayerPosy == map[0].size() - 1) {

		return CountTile + 1;
	}


	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			if ((PlayerPosx) == i && ((PlayerPosy) == j)) {
				cout << "▲";
				continue;
			}

			if (map[i][j] == 1) {
				cout << "□";
			}
			else if (map[i][j] == 2) {
				cout << "◆";
			}
			else { cout << "■"; }
		}
		cout << endl;
	}
	cout << endl;


	for (int i = 0; i < 4; i++) {
		//
		int exPlayerPosx = PlayerPosx + mapMove[i][0];
		int exPlayerPosy = PlayerPosy + mapMove[i][1];




		if ((0 <= exPlayerPosx && 0 <= exPlayerPosy) && (map.size() > exPlayerPosx && map[0].size() > exPlayerPosy))
		{
			if (map[exPlayerPosx][exPlayerPosy] == 1)
			{
				Rood[0][roodCount] = exPlayerPosx;
				Rood[1][roodCount] = exPlayerPosy;
				roodCount++;
			}
		}
	}

	vector<int> Rvalue = {};


	if (roodCount > 0) {

		map[(PlayerPosx)][(PlayerPosy)] = 0;

		CountTile++;

		for (int i = 0; i < roodCount; i++) {
			Rload CroosRload1 = { CountTile,Rood[0][i],Rood[1][i] };
			CroosRload.push(CroosRload1);
		}
		return 0;

	}
	else {
		map[(PlayerPosx)][(PlayerPosy)] = 0;
		return-1;
	}


}
/*
int mAPsolution(vector<vector<int> >& map, int PlayerPosx, int PlayerPosy, int CountTile)
{

	int movedPlayerx = -99;
	int movedPlayery = -99;



	while (true)
	{

		if (PlayerPosx == map.size() - 1 && PlayerPosy == map[0].size() - 1) {

			return CountTile + 1;
		}

		for (int i = 0; i < map.size(); i++)
		{
			for (int j = 0; j < map[0].size(); j++)
			{
				if ((PlayerPosx) == i && ((PlayerPosy) == j)) {
					cout << "▲";
					continue;
				}

				if (map[i][j] == 1) {
					cout << "□";
				}
				else if (map[i][j] == 2) {
					cout << "◆";
				}
				else { cout << "■"; }
			}
			cout << endl;
		}
		cout << endl;





		//vector<tuple<int, int>>Rood;

		vector<int> Rood[2] = { {},{} };


		for (int i = 0; i < 4; i++) {
			//
			int exPlayerPosx = PlayerPosx + maps[i][0];
			int exPlayerPosy = PlayerPosy + maps[i][1];

			//if ((movedPlayerx == exPlayerPosx && movedPlayery == exPlayerPosy))continue;


			if ((0 <= exPlayerPosx && 0 <= exPlayerPosy) && (map.size() > exPlayerPosx && map[0].size() > exPlayerPosy))
			{
				if (map[exPlayerPosx][exPlayerPosy] == 1)
				{
					Rood[0].push_back(exPlayerPosx);
					Rood[1].push_back(exPlayerPosy);
				}
			}
		}

		vector<int> Rvalue = {};


		if (Rood[0].size() > 1) {



			map[(PlayerPosx)][(PlayerPosy)] = 2;
			CountTile++;

			for (int i = 0; i < Rood[0].size(); i++) {
				Rload CroosRload1 = { CountTile,Rood[0][i],Rood[1][i] };
				CroosRload.push(CroosRload1);
			}
			return 0;

		}
		else if (Rood[0].size() == 1) {
			map[(PlayerPosx)][(PlayerPosy)] = 0;

			CountTile++;
			Rload CroosRload1 = { CountTile,Rood[0][0],Rood[1][0] };
			CroosRload.push(CroosRload1);
			return 0;
		}
		else {
			return-1;
		}

	}

}
*/
//BFS algorithm Recursive funtion 

//
//int BFS_RecursiveFunction(vector<vector<int> >& map, int PlayerPosx, int PlayerPosy, int CountTile) {
//
//	int movedPlayerx = -99;
//	int movedPlayery = -99;
//
//	if (PlayerPosx == map.size() - 1 && PlayerPosy == map[0].size() - 1) {
//
//		return CountTile + 1;
//	}
//
//	while (true)
//	{
//
//
//
//		for (int i = 0; i < map.size(); i++)
//		{
//			for (int j = 0; j < map[0].size(); j++)
//			{
//				if ((PlayerPosx) == i && ((PlayerPosy) == j)) {
//					cout << "▲";
//					continue;
//				}
//
//				if (map[i][j] == 1) {
//					cout << "□";
//				}
//				else if (map[i][j] == 2) {
//					cout << "◆";
//				}
//				else { cout << "■"; }
//			}
//			cout << endl;
//		}
//		cout << endl;
//
//
//
//
//
//		//vector<tuple<int, int>>Rood;
//
//		vector<int> Rood[2] = { {},{} };
//
//		for (int i = 0; i < 4; i++) {
//			//
//			int exPlayerPosx = PlayerPosx + maps[i][0];
//			int exPlayerPosy = PlayerPosy + maps[i][1];
//
//			if ((movedPlayerx == exPlayerPosx && movedPlayery == exPlayerPosy))continue;
//
//
//
//			if ((0 <= exPlayerPosx && 0 <= exPlayerPosy) && (map.size() > exPlayerPosx && map[0].size() > exPlayerPosy))
//			{
//				if (map[exPlayerPosx][exPlayerPosy] == 1)
//				{
//					Rood[0].push_back(exPlayerPosx);
//					Rood[1].push_back(exPlayerPosy);
//				}
//			}
//
//		}
//		if (Rood[0].size() > 1) {
//			for (int i = 0; i < Rood[0].size(); i++) {
//				
//				int Value = (Rood[0][i] * 10) + Rood[1][i];
//				
//				if (CountTile > Croosmap[Value])return-1;
//
//				Croosmap[Value] = CountTile;
//				
//				
//				CroosRload.push(new Rload{ Rood[0][i],Rood[1][i],CountTile });
//			}
//
//		}
//		else if (Rood[0].size() == 1) {
//			movedPlayerx = PlayerPosx;
//			movedPlayery = PlayerPosy;
//			PlayerPosx = (Rood[0][0]);
//			PlayerPosy = (Rood[1][0]);
//			CountTile++;
//		}
//		else {
//			
//			return -1;
//		}
//
//
//	}
//
//}

/*
int mAPsolution(vector<vector<int> > map, int PlayerPosx, int PlayerPosy, int CountTile)
{

	if (PlayerPosx == map.size() - 1 && PlayerPosy == map[0].size() - 1) {

		return CountTile + 1;
	}

	while (true)
	{
		if (PlayerPosx == map.size() - 1 && PlayerPosy == map[0].size() - 1) {

			return CountTile + 1;
		}
		if (CountTile >= smallerD) {
			return-1;
		}

		for (int i = 0; i < map.size(); i++)
		{
			for (int j = 0; j < map[0].size(); j++)
			{
				if ((PlayerPosx) == i && ((PlayerPosy) == j)) {
					cout << "▲";
					continue;
				}

				if (map[i][j]) {
					cout << "□";
				}
				else { cout << "■"; }
			}
			cout << endl;
		}
		cout << endl;


		//vector<tuple<int, int>>Rood;

		vector<int> Rood[2] = { {},{} };
		for (int i = 0; i < 4; i++) {
			//
			int exPlayerPosx = PlayerPosx + maps[i][0];
			int exPlayerPosy = PlayerPosy + maps[i][1];
			if ((0 <= exPlayerPosx && 0 <= exPlayerPosy) &&
				(map.size() > exPlayerPosx && map[0].size() > exPlayerPosy)

				) {
				if (map[exPlayerPosx][exPlayerPosy])
				{
					Rood[0].push_back(exPlayerPosx);
					Rood[1].push_back(exPlayerPosy);
				}
			}
		}

		if (Rood[0].size() > 1) {

			vector<int> Rvalue = {};

			 int SRood = { (PlayerPosx*10)+(PlayerPosy) };

			if (Croosmap[SRood] == 0 || Croosmap[SRood] >= CountTile) {
				Croosmap[SRood]=CountTile;
			}
			else {
				return-1;
			}
			map[PlayerPosx][PlayerPosy] = 0;
			CountTile++;

			for (int i = 0; i < Rood[0].size(); i++) {
				int RoodPos[2] = { Rood[0][i],Rood[1][i] };

				int returnValue = mAPsolution(map, RoodPos[0],RoodPos[1], CountTile);

				if (returnValue > 0) {
					Rvalue.push_back(returnValue);
				}
			}

			if (Rvalue.size() > 0) {
				int smaller = Rvalue[0];
				for (int values : Rvalue) {
					if (smaller > values) {
						smaller = values;
					}
				}
				smallerD = smaller;
				return smaller;
			}
			return -1;
		}
		else if (Rood[0].size() == 1) {
			map[PlayerPosx][PlayerPosy] = 0;

			PlayerPosx = (Rood[0][0]);
			PlayerPosy= (Rood[1][0]);

			CountTile++;


		}
		else {
			return -1;
		}
	}

}
*/

#pragma endregion


int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	queue<int> BFS = {};
	BFS.push(21);
	for (int i = 2; i <= n; i++) {

		while (!BFS.empty())
		{
			int data = BFS.front();
			BFS.pop();
			int x = (data / 10)-1;
			int y = (data % 10)-1;
			if (computers[x][y] == 1) {
				computers[x][y]= 
			}
			else {

			}

		}


		if (computers[i-1][i-1] == 1) {
			BFS.push({ ((i - 1) * 10) + i });
			BFS.push({ ((i + 1) * 10) + i });
			// bfs 에서 꺼내서 반복할때 i보다 큰지 작은지 확인하고 틀을 넘지않게끔 반복
		}


	}



	return answer;
}

int main() {


	solution(3, { {1,1,0}, {1,1,0}, {0,0,1} });






















	string STR = "abab";
	//cin >> STR;
	int Odd = 0;
	int SameNum = 0;
	char SameChar = STR[STR.size() - 1];

	for (int i = 0; i < STR.size() - 1; i++)
	{
		if (SameChar == STR[i]) {
			if ((STR.size() - i) % 2) {
				Odd = 1;
			}
			else {
				Odd = 0;
			}

			for (int j = i; j < i + ((STR.size() - i) - 1 / 2); j++)
			{

				if (STR[j] == STR[STR.size() - (j - i) - 1]) {
					SameNum++;
				}
				else {
					break;
				}
			}

			if (STR.size() - i == SameNum * 2 + Odd) {
				break;
			}
			else
			{
				SameNum = 0;
			}

		}

	}
	if (SameNum == 0) {
		cout << STR.size() * 2 - 1;
	}
	int b = STR.size() - (STR.size() - ((SameNum * 2) + Odd));
	cout << b;




	vector<vector<int> > maps = { {1,0,1,1,1} ,{1,0,1,0,1 }, { 1,0,1,1,1 }, { 1,1,1,0,1 }, { 0,0,0,0,1 }
	};
	int answer = -1;
	int x = 0;
	int y = 0;
	Rload Cro = { 0,0,0 };
	CroosRload.push(Cro);
	while (!CroosRload.empty())
	{

		Rload data = CroosRload.front();
		CroosRload.pop();
		int Score = 0;
		int roodCount = 0;

		if (data.x == maps.size() - 1 && data.y == maps[0].size() - 1) {

			return data.value + 1;
		}

		for (int i = 0; i < maps.size(); i++)
		{
			for (int j = 0; j < maps[0].size(); j++)
			{
				if ((data.x) == i && ((data.y) == j)) {
					cout << "▲";
					continue;
				}

				if (maps[i][j] == 1) {
					cout << "□";
				}
				else if (maps[i][j] == 2) {
					cout << "◆";
				}
				else { cout << "■"; }
			}
			cout << endl;
		}
		cout << endl;


		for (int i = 0; i < 4; i++) {
			//
			int exPlayerPosx = data.x + mapMove[i][0];
			int exPlayerPosy = data.y + mapMove[i][1];




			if ((0 <= exPlayerPosx && 0 <= exPlayerPosy) && (maps.size() > exPlayerPosx && maps[0].size() > exPlayerPosy))
			{
				if (maps[exPlayerPosx][exPlayerPosy] == 1)
				{
					Rood[0][roodCount] = exPlayerPosx;
					Rood[1][roodCount] = exPlayerPosy;
					roodCount++;
				}
			}
		}

		vector<int> Rvalue = {};


		if (roodCount > 1) {

			maps[(data.x)][(data.y)] = 0;

			data.value++;

			for (int i = 0; i < roodCount; i++) {
				Rload CroosRload1 = { data.value,Rood[0][i],Rood[1][i] };
				CroosRload.push(CroosRload1);
			}
			continue;
		}
		else if (roodCount == 1) {
			data.x = Rood[0][0];
			data.y = Rood[0][1];
			data.value++;
			continue;
		}
		else {
			maps[(data.x)][(data.y)] = 0;
			continue;
		}


	}
	cout << answer;





	/*	Rload a = CroosRload.front();
		CroosRload.pop();

		int Score = mAPsolution(maps, a.x, a.y, a.value);



		if (Score > 0) {
			answer = Score;
			break;
		}*/


	cout << answer;




















	//solution(7, 3, { 4,2,4,5,3,3,1 });

	vector<int> ans = {};
	auto a = hackyoul(10, 4, ans);


	//string s =")()(";
	//int garho = 0;
	//bool answer = true;
	//for (auto i : s) {
	//	if (i == '(')garho++;
	//	else garho--;

	//	if (garho < 0) {
	//		answer= false;
	//	}

	//}
	//
	//if (garho != 0) answer = false;





	int n = 10;  long long k = 20;
	//[1,2,3,4]
	//[1,2,4,3]

	//vector<int> answer;



#pragma region bind 테스트

	//std::function<void(int)> funcName1 = EraToseTenes_chea;
	//std::function<void(int)> funcName2 = [](int a) {};
	//std::function<void(int)> funcName3= std::bind(EraToseTenes_chea, 15);
	//auto funcName4= std::bind(EraToseTenes_chea, 15);
	//int a=10;
	//auto funcName5 = std::bind(EraToseTenes_chea, cref(a));
	//auto funcName6 = std::bind(EraToseTenes_chea, cref(a),EraToseTenes_chea(2));

	//funcName1(2);
	//funcName2(1);
	//funcName3(10);//bind 인관계로 15로 실행
	//funcName4();
	//a = 20;
	//funcName5();
#pragma endregion



	Player p = { Player(4) };
	//Player::playerIdle();
	Player* _P = &p;
	//Deleg delg;
	//delg.funcs = &Player::PlayerRender;
	//p.b = 20;
	//(p.*delg.funcs)(p);
	//

	//void(*fun)(Player pa);
	//fun = [](Player p) {p.playerIdle(); };
	//fun(p);

	//delg.Deleg.push([_P]() {Player(*_P).playerIdle(); });
	//delg.Deleg.push([_P]() {_P->playerMove(); });
	//delg.Deleg.back()();
	//
	//p.playerIdle();

	int i = 8;
	auto f = [i]() {
		int j = 2;
		auto m = [=] { cout << i / j; };
		m();
	};
	f();
	const int UpdateRate = 2;
	PlayerState State;
	Deleg StateDelg[PlayerState::GenderCount][UpdateRate] = { { {} ,{} } ,{ {} ,{} } ,{ {}, {} } };
	StateDelg[0][0].Deleg.push_back([=]() {cout << endl; _P->playerMove(); cout << endl;  });
	StateDelg[0][1].Deleg.push_back([_P]() {_P->playerMove(); _P->playerIdle(); });


	StateDelg[1][0].Deleg.push_back([_P]() {_P->playerMove(); _P->playerIdle(); });
	StateDelg[1][1].Deleg.push_back([_P]() {_P->playerMove(); _P->playerIdle(); });


	StateDelg[2][0].Deleg.push_back([_P]() {_P->playerMove(); cout << "1Update End" << endl; });
	StateDelg[2][0].Deleg.push_back([_P]() {_P->playerMove(); cout << "1Update End" << endl; });
	StateDelg[2][0].Deleg.push_back([_P]() {_P->playerMove(); cout << "1Update End" << endl; });
	StateDelg[2][0].Deleg.push_back([_P]() {_P->playerMove(); cout << "1Update End" << endl; });
	StateDelg[2][0].Deleg.push_back([_P]() {_P->playerMove(); cout << "1Update End" << endl; });

	StateDelg[2][1].Deleg.push_back([_P]() {_P->playerMove(); _P->playerIdle(); });
	//switch (State)
	//{
	//case Move:
	//	break;
	//case Idel:
	//	break;
	//case Skill:
	//	break;
	//default:
	//	break;
	//}

	for (int i = 0; i < GenderCount; i++)
		for (int j = 0; j < UpdateRate; j++) {
			for (int k = 0; k < StateDelg[i][j].Deleg.size(); k++) {
				cout << PlayerState(i) << "," << j << "번째 함수 실행:";
				(StateDelg[i][j].Deleg[k]());
			}

		}

	//cout << solution(5, 3);


	//vector<int> citations = {3,0,6,1,5};
	//int answer = 0;
	//sort(citations.begin(), citations.end());
	//for (int i = 0; i < citations.size(); i++) {
	//	if (citations[i] >= i) {
	//		answer = citations.size() - i;
	//		break;
	//	}
	//}
	//vector<string> babbling = { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" };
	//vector<string> CanSay = { "aya","ye","woo","ma" };
	//int answer = 0;

	//for (auto a : babbling) {
	//	for (int i = 0; i < a.size(); i++) {
	//		for (int j = 0; j < CanSay.size(); j++) {

	//		}
	//	}
	//}
}
#pragma region MyRegion
//MyClass m;
//m.b = 1;
//int MaxNum = 0;
//vector<vector<int>> Grap;
//그래프문제 - 받는 전체 배열의 가장큰 수를 받는다
// 그 크기만큼 배열크기를 키워준다. 양방향 벡터

// [1.2] 면 1ㅡ2 2ㅡ1 둘다 배열을 채워준다.
// 길찾기 알고리즘을 짜준다
// [1에서 시작해서 [1,2] 면 2 의 [1] [3] [4] 가 있으면 이전노드의 정보를 들고오고
// 크기만큼 일반 배열생성
// 도착 하는 가장빠른 숫자를 그배열에 입력
// 보다 커지면 목표 변경
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

/*실패한 문제*/

//사각형 자르기
/*
* https://m.blog.naver.com/orbis1020/220664563768
사각형 자르기 문제 패턴을 찾는 부분에서 약간 잘못확인해서 답이랑 거리가 좀있었음
ppt로 값확인할때 w+h-1 라는 값이 특정 소수에서 나오는걸 보고 다른 값들도 계산해 보고
 최대공약수 가 1이 나온것과 아닌것 의 결가값만 비교하였어도 답을 추론할수 있었을거 같음..
 답을 봐버려서 아쉽고, 패턴을 찾을때 귀찮다고 특정부분에서 추측한부분만 계속 생각한게 아쉬움

 대각선이 지나는 격자점의 개수가 가로, 세로 길이의 최대공약수라는 점 , 한줄씩도 계산해 봤지만 눈치못쳄..
*/
class BlockCalculate {
public:
	double ratio = 0;
	int W_num = 0;
	int Max_num = 0;
	//vector<bool> b;
	long long OneBlockCalculate();
};
long long BlockCalculate::OneBlockCalculate() {
	if (W_num == Max_num)return 0;
	long long ih = floor(ratio * (W_num));
	long long ih2 = ceil((ratio) * (W_num + 1));
	W_num += 1;
	if (ih == ih2)
		return (OneBlockCalculate() + 1);
	else if (ih < ih2)
		return (OneBlockCalculate() + (ih2 - ih));
}
//하나씩 실행해보는방법 onblock함수


//해법 계산법들
int gcd(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
//long long asolution(int w, int h) {
//	long long answer;
//	for (int i = 0; i < w; ++i) {
//		answer += (int)((double)h * i / w);
//	}
//
//	return 2 * answer;
//
//	return   ceil(double(h) / w) * w;
//}

/*실패한 문제*/


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
	// 중복비교가 생기나 1~9임으로 그냥 중복비교 제거를 생략함
	//9번만 1번씩 비교해봐도 가능하지만 귀찮음
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
		//나중에 찾기위해 테그 달기 ( 특정 문자 제거)
		s2.erase(remove(s2.begin(), s2.end(), '0'), s2.end());
		answer[1] += (s.length() - s2.length());
		s = "";
		int lenth = s2.length();

		//나중에 찾기위해 테그 달기 ( 10진수 2진수 변환)
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



	생각 하던 풀이는 이거랑 비슷한데 더 생각안하고 풀어도 몇줄 차이 안날거 같아서 걍 풀었더니 길어졌다
	const char을 추가함으로 for문으로 검색후 비교를 구현한 부분이 참고할수있는점인거 같다

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
//이게왜 2단계문제에 7점?
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
	식 힌트 보고풀었는데
	그 어떤 크기의 타입을 써도 오버플로우가 난다
	수학의 이해도가 필요한 문제
	( A + B ) % C  = (( A % C ) + ( B % C ))%C

	(50000 +50000 ) / @
	보다
	50000/@ + 50000/@ 가 계산 숫자 길이가 짧다.
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

//바바리맨 스파이 - 해쉬+확률 사용문제
//알고리즘 배워둬야하는이유  2점인 이유를 모르긴 하겠는데...
//hash_map 사용안했으면 for문 많이 돌려야했고
// 수학 식이없었으면 불가능한 풀이
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
	 해쉬 사용 하면 이렇게 가능하다.
	 이중 for문 사용한건 같다.
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

	이건 비슷하게 했었는데 이중for문을 안돌려도
	사전순 정렬이라 가능하다
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
	//겹치는거 삭제
	answer.erase(unique(answer.begin(), answer.end()), answer.end());
	return answer;
}
//문제가 간단한 만큼 다른사람들 풀이가 대단하다. a부터 b까지 덧셈
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

	/* 비트연산 풀이
	  if (a > b) a ^= b ^= a ^= b;
	answer = (long long)b * -~b / 2 - (long long)a * ~-a / 2;
	*/

	/* 시그마 이용 (공식풀이)
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

	//sort (s.begin(), s.end(), greater<char>()); 짧은풀이

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
		//3(n)진법에서 10진법 재변환법 
		answer = answer * 3 + (as[i]);
	}
	return answer;
}

//n * (n+1) / 2 가우스 공식...
//수학을 기억해야 하는이유
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

//짝지어 제거하기 aa
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

//특정수 내 소수구하기
//에라토스테네스의 체
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

// 10진수-> 3진수 124로 변환
string oenTwoFour_Wold(int a) {
	//소 뒷걸음질 치다 쥐잡은격으로  풀었음
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

//응급보트 2명만 타고 탈출
int LifeBoat(vector<int> people, int Limit) {
	int answer;
	int lef = 0;

	//직접사용한거 사용한거보다 훨씬빠름..
	sort(people.begin(), people.end());
	for (int i = people.size() - 1; i >= 0; i--)
	{
		//가장 짧은 풀이는 for문안에 4줄
		/*
			for (int i = 0, j = N - 1; i <= j; i++) {
				ㄴ i =left j = right 같거나 작으면 나오기 i++ -> 작은쪽에서 큰거 비교
				 if (people[i] + people[j] <= limit) {
					j--;
					ㄴ 제일작은것과 제일큰것 비교후 가능하면 제일큰수 제외;
					}

				  res++;
				ㄴ어짭히 1명이든 2명이든 보트는 타니까 ++ 안타는경우가 없으니 무조건 ++해줘둬 됨
			}
		*/
		//ereas 함수가 생각보다 많이느림
		// 너무 복잡하게 생각했었음
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

//새 아이디 만들기
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

//다트 게임 점수구하기
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

#pragma region vector 공간 확보
//vector<int> v;
//vector<int> v1;
//for (int i = 0; i < 100; i++) {
//	v.push_back(i);
//	v1.reserve(i+1); //공간확보
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

//배열 넣어주기 -> 퀵소트정렬 -> 다시 long 에 넣어주기 식으로 구현
// 다른사람 
/*
	string str = to_string(n);
	sort(str.begin(), str.end(), greater<char>());
	answer = stoll(str);

	또는 그냥 sort 사용ㅋㅋ..


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

// 자신의 절반 잡고 좌우 

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
	//가장 짧은 풀이는 한줄이다.(  arr.erase(unique(arr.begin(), arr.end()),arr.end());
}

vector<int> GCD_LCM(int m, int n) {

	vector<int> answer = { 0 };

	answer[0] = n >= m ? m : n;

	while ((n % answer[0] != 0) || (m % answer[0] != 0))
	{
		if (answer[0] == 1)break;
		answer[0]--;
	}
	answer.push_back((n * m) / answer[0]); //최대공약수 구하는공식 n*m )/최소공배수
	return answer;
}

int Collera(int num) {
	long anum = num; //int 쓰면 오버플로우 나면서 488에서 while문을탈출한다.
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

//포인터 이유를 모르겠음 (2중포인터 써야하나
/*


	for (int i = 0; i < report.size(); i++) {

		string reprotMessage; //현재 이름
		vector<bool>  *Reporter1 =nullptr; // 이름에 맞는 신고자배열
		for (int j = 0; j < report[i].size(); j++) {
			if (report[i][j] == ' ') { // 스페이스바로 초기화
				Reporter1 = &ReportCount[ID.find(reprotMessage)->second]; //ID[reprotMessage]
				reprotMessage = "";
				continue;
			}
			reprotMessage += report[i][j];

		}
		cout << &Reporter1[ID.find(reprotMessage)->second] ;
	}

	왜?
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

	//이동위치는 현재위치 - + 도착위치
	//  ZAQ <- 현재 pos위치 X    23         25 0 16              2번 현재위치 1번칸 z        2번 오른쪽 한번이동 z 에서 A로 한번  2번칸 a     11번 한칸 이동 A > Q   16 - 0 =16, 0 -> 25-16 = (9+1),  + 1칸이동

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

 1등 - 6개 일치
 2등 - 5개 일치
 3등 - 4개 일치
 4등 - 3개 일치
 5등 - 2개 일치
	이하 낙첨 6

  0이 틀리거나 맞았을때

   당첨번호 [31 10 45 1 6 19]
   현재번호 [31  0 44 1 0 25]

  o ㅁ x o ㅁ x   두개 정답, 두개 오답, 두개 미정

			 ㅁ 이 x일때 2개 정답 5등
			 ㅁ 이 o일때 4개정답 3등

*/

vector<int> LottosNum(vector<int> lottos, vector<int> win_nums) {
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
//프로그래머스 해쉬1
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


//백준 뭐였지
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

int Addercycle(int Num) {

	int answer = 0;
	if (Num < 10) Num *= 10;
	int temp = Num;
	while (true) {
		int front = temp / 10;
		int back = temp % 10;
		int c = (front + back) % 10;
		temp = (back * 10) + c;
		answer++;
		if (temp == Num) break;
	}

	return answer;
}

/*
장르별로 재생된 노래를 2개씩 모아야함
1장르 2노래
  노래는 각자 고유번호가 있음

1. 장르 고를때 -> 내부 노래중 1위들 비교
2. 장르 내에서 수록 -> 2만회,1만회 순으로 수록
3. 장르 내에서 횟수가 같으면 -> 고유번호가 낮은노래 부터 (고유번호는 배열번호)

노래 장를 genres / 노래별 재생횟수 plays 가 주어질때 배스트
앨범에 들어갈 노래 고유 번호를 순서대로 나열

genres[i]는 고유번호가 i인 노래의 장르입니다.
plays[i]는 고유번호가 i인 노래가 재생된 횟수입니다.
genres와 plays의 길이는 같으며, 이는 1 이상 10,000 이하입니다.
장르 종류는 100개 미만입니다.
장르에 속한 곡이 하나라면, 하나의 곡만 선택합니다.
모든 장르는 재생된 횟수가 다릅니다


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


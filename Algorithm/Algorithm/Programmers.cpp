#include<queue>
#include <unordered_map>
#include<vector>
#include<iostream>
#include<map>
using namespace std;


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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(NULL);
	MinecraftCreatHouse();

	return 0;
}
//#define cost 0
//#define Nextroad 1
//#define MM_Num  9999999
//const auto& mt = make_tuple(MM_Num, MM_Num);
//void Distory(unordered_map<int, vector<tuple<int, int>>>& Umap, vector< queue<int>>& nodeGansun, int end) {
//
//	while (!nodeGansun[end].empty())
//	{
//		int num = nodeGansun[end].front();
//		nodeGansun[end].pop();
//		for (auto& um : Umap[num]) {
//			if (get<1>(um) == end) {
//				um = make_tuple(MM_Num, MM_Num);
//				Distory(Umap, nodeGansun, num);
//			}
//		}
//	}
//}
//void find_FIRST_DS(unordered_map<int, vector<tuple<int, int>>>& Umap, int start, int end, int nodesize) {
//	priority_queue<tuple<int, int, int>> nextxy;
//	vector<int> noodBool(nodesize + 1, MM_Num);
//	vector< queue<int>>nodeGansun(nodesize + 1, queue<int>());
//	noodBool[start] = MM_Num;
//
//	tuple<int, int, int> nxy;
//	int d = 0, arrowRoad = 0, arrowcost = 0;
//	nextxy.emplace(make_tuple(0, start, start));
//
//	int first = MM_Num;
//	while (!nextxy.empty())
//	{
//
//		nxy = nextxy.top();
//		nextxy.pop();
//		arrowcost = -get<0>(nxy);
//		arrowRoad = get<1>(nxy);
//		if (get<1>(nxy) == end) {
//			if (first == get<0>(nxy)) {
//				first = get<0>(nxy);
//				break;
//			}
//		}
//		if (noodBool[arrowRoad] == MM_Num || noodBool[arrowRoad] > (arrowcost)) {
//			noodBool[arrowRoad] = arrowcost;
//			nodeGansun[arrowRoad] = queue<int>();
//			nodeGansun[arrowRoad].push(get<2>(nxy));
//		}
//		else if (noodBool[arrowRoad] == (arrowcost))
//		{
//			nodeGansun[arrowRoad].push(get<2>(nxy));
//			continue;
//		}
//		else  continue;
//		d = get<0>(nxy);
//		for (int i = 0; i < Umap[get<Nextroad>(nxy)].size(); ++i) {
//
//			tuple<int, int> arrow = Umap[get<1>(nxy)][i];
//			arrowRoad = get<1>(arrow);
//			arrowcost = get<0>(arrow);
//			if (noodBool[arrowRoad] == MM_Num || noodBool[arrowRoad] > (arrowcost + -(d))) {
//				nextxy.emplace(make_tuple(-(arrowcost + -(d)), get<1>(arrow), get<1>(nxy)));
//			}
//		}
//	}
//	while (!nextxy.empty()) {
//		auto b = nextxy.top();
//		nextxy.pop();
//		if (get<1>(b) == end && get<0>(b) == first) {
//			nodeGansun[end].push(get<2>(b));
//		}
//	}
//	Distory(Umap, nodeGansun, end);
//	return;
//}
//
//int find_second_DS(unordered_map<int, vector<tuple<int, int>>>& Umap, int start, int end, int nodesize) {
//	priority_queue<tuple< int, int>> nextxy;
//	vector<bool> noodBool(nodesize + 1, false);
//	tuple<int, int> nxy;
//	nextxy.emplace(make_tuple(0, start));
//	bool lastnode = false;
//	noodBool[start] = true;
//	while (!nextxy.empty())
//	{
//		nxy = nextxy.top();
//		nextxy.pop();
//		noodBool[get<1>(nxy)] = true;
//
//		if (get<1>(nxy) == end) {
//			return  (-get<0>(nxy));
//		}
//		for (const auto& arrow : (Umap[get<1>(nxy)])) {
//			if (get<1>(arrow) == MM_Num)continue;
//			if (noodBool[get<1>(arrow)]) {
//				continue;
//			}
//			nextxy.emplace(make_tuple(-(get<0>(arrow) + -(get<0>(nxy))), get<1>(arrow)));
//		}
//	}
//	return (-1);
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cin.tie(NULL);
//	int NodeSize = 0, NodeLoadSize = 0, Start = 0, end = 0;
//	int node = 0, Xnode = 0, Dis = 0;
//	unordered_map<int, vector<tuple<int, int>>> Umap;
//	vector<int> answer;
//	while (true)
//	{
//		cin >> NodeSize >> NodeLoadSize;
//		if (NodeSize == 0 && NodeLoadSize == 0)
//			break;
//		cin >> Start >> end;
//
//		Umap.clear();
//		for (int i = 0; i < NodeLoadSize; i++)
//		{
//			cin >> node >> Xnode >> Dis;
//			Umap[node].emplace_back(make_tuple(Dis, Xnode));
//		}
//
//		find_FIRST_DS(Umap, Start, end, NodeSize);
//		answer.emplace_back(find_second_DS(Umap, Start, end, NodeSize));
//	}
//	for (const auto& an : answer) {
//		printf("%d\n", an);
//	}
//	return 0;
//}
void hose(vector<int>* star, int nextHouse) {
	/*
				if (MinimumDis == 0) {
				MinimumDis = get<0>(First);
			}
			else if (MinimumDis < get<0>(First)) {
				cout << get<0>(First);
				break;
			}
			else if (get<0>(First) == -1) {
				cout << -1;
				break;
			}
*/

}


/*

	int a = 0;
	string s = ")()(";
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> s;
		cout<< (garho(s)? "YES\n" : "NO\n");

	}
*/
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


int msize = 4;
/*	//int** d = (int**)malloc(sizeof(int*) * 50);
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

	cout<<Rechess(a, b, d);*/
int Rechess(int w, int h, vector<vector<bool>>& map) {

	int Lower = 65;
	int ms = 0;
	//»óÇÏÁÂ¿ì 8Ä­±âÁØ Àý¹Ý¾¿ ÃÖ¼Ò °ø°£È®º¸                
	for (int i = msize; i < w - msize + 1; i++) {
		for (int j = msize; j < h - msize + 1; j++) {
			//È¦Â¦ È¦Â¦ È¦È¦Â¦¤A °è»ê
			for (int b = 0; b < 2; b++) {
				int Lowers = 0;

				for (int k = i - msize; k < i + msize; k++) {
					for (int n = j - msize; n < j + msize; n++) {
						//cout << (map[k][n] ? "¡á" : "¡à"); // ÀÚ¸¥°Å °ËÅä
						//cout << (((n + k) + b)%2); È¦Â¦ ¸¸µé±â
						//Â¦¼ö È¦¼ö °ËÅä
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


int solution(vector<int> money) {
	int answer = 0;
	vector<int> doit(money.size());
	int hier = 0;

	for (int i = 0; i < money.size(); i++) {
		if (hier < money[i]) hier = i;
	}
	doit[hier] = money[hier];

	hose(&doit, hier);


	return answer;
}



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

int solution(vector<vector<int>> land) {
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
/*


*/



/* ±×·¡¼­ ÃÊ·Ï¿ÊÀÌ Á©´ÙÁÒ?
static int const nextlands[4][2]{ {0,1}, {1,0}, {-1,0}, {0,-1} };
int find_zelda(vector<vector<int>>& land, vector<vector<int>>& sland) {
	priority_queue<pair< int,pair<int, int>>> nextxy;
	nextxy.push(make_pair(sland[0][0], make_pair(0, 0)));

	sland[0][0] = land[0][0];

	while (nextxy.size() != 0)
	{

		pair<int,pair<int, int>> nxy = nextxy.top();
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

					nextxy.push(make_pair(-sland[x][y],make_pair(x, y)));
				}
				if(x== sland.size()-1 && y == sland.size()-1)return sland[sland.size() - 1][sland.size() - 1];
			}
		}

	}
	return sland[sland.size() - 1][sland.size() - 1];

}

int main() {
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
*/


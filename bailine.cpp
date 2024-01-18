#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct ToaDo
{
	int dong, cot;
};
typedef struct ToaDo TOADO;

int main()
{
	ifstream FileIn;
	FileIn.open("input2.txt", ios_base::in);

	int n, dong_start, cot_start, dong_end, cot_end;
	bool truyvet[9][9] = {false};

	FileIn >> n >> dong_start >> cot_start >> dong_end >> cot_end;

	// Vi trong lap trinh cau truc mang bat dau tu 0 nen phai tru di 1
	dong_start--;
	cot_start--;
	dong_end--;
	cot_end--;

	vector<vector<int> > map;
	map.resize(n); // cap phat so dong

	for(int i = 0; i < n; ++i)
	{
		map[i].resize(n); // voi moi dong cap phat
		for(int j = 0; j < n; ++j)
			FileIn >> map[i][j];
	}

	TOADO x;
	x.dong = dong_start;
	x.cot = cot_start;

	queue<TOADO> q;
	q.push(x);
	truyvet[x.dong][x.cot] = true; // tai vi tri nay da duoc dua vao hang doi de chuan bi xet

	bool TimThay = false; // mac dinh ban dau la chua tim thay duong di

	// Hang doi lien tuc lay  phan tu dau hang doi ra de xét => qua trinh lap lai lien tuc den khi hang doi rong
	while(!q.empty())
	{
		// Lay phantu ra de xet
		TOADO a = q.front();
		q.pop();

		// Xet toa do vua lay ra de xem no co the di chuyen tiep toi nhung vi tri nao tiep theo?
		// Dieu kien de di chuyen phai thoa ca 3 dieu sau: 1/ Vi tri do phai la vi tri hop le & 2/ O do dang trong & 3/ Nuoc di do chua duoc xet
		
		// (dong + 1, cot)
		if(a.dong + 1 < n && map[a.dong + 1][a.cot] == 0 && truyvet[a.dong + 1][a.cot] == false)
		{
			// Khi thoa 3 dieu kien trrn thi se tiem hanh dua vao hang doi de chuan bi xet cho tuong lai
			TOADO s;
			s.dong = a.dong + 1;
			s.cot = a.cot;
			q.push(s); // Dua vao hang doi
			truyvet[s.dong][s.cot] = true; // Tai vi tri nay da duoc dua vao hang doi de chuan bi xet

			// Dieu kien dung khi vi tri toa do moi dua vao chinh la dich den
			if(s.dong == dong_end && s.cot == cot_end)
			{
				TimThay = true; // Danh dau lai la da tim thay duong di
				break; // Thoat khoi qua trinh lap va ket luan
			}
		}

		// (dong - 1, cot)
		if(a.dong - 1 >= 0 && map[a.dong - 1][a.cot] == 0 && truyvet[a.dong - 1][a.cot] == false)
		{
			TOADO s;
			s.dong = a.dong - 1;
			s.cot = a.cot;
			q.push(s); // Dua vao hang doi
			truyvet[s.dong][s.cot] = true; // Tai vi tri nay da duoc dua vao hang doi de chuan bi xet

			// Dieu kien dung khi vi tri toa do moi dua vao chinh la dich den
			if(s.dong == dong_end && s.cot == cot_end)
			{
				TimThay = true; //  Danh dau lai la da tim thay duong di
				break; // Thoat khoi qua trinh lap va ket luan
			}
		}

		// (dong, cot + 1)
		if(a.cot + 1 < n && map[a.dong][a.cot + 1] == 0 && truyvet[a.dong][a.cot + 1] == false)
		{
			TOADO s;
			s.dong = a.dong;
			s.cot = a.cot + 1;
			q.push(s); // Dua vao hang doi
			truyvet[s.dong][s.cot] = true; //  Tai vi tri nay da duoc dua vao hang doi de chuan bi xet

			// Dieu kien dung khi vi tri toa do moi dua vao chinh la dich den
			if(s.dong == dong_end && s.cot == cot_end)
			{
				TimThay = true; // Danh dau lai la da tim thay duong di
				break; // Thoat khoi qua trinh lap va ket luan
			}
		}

		// (dong, cot - 1)
		if(a.cot - 1 >= 0 && map[a.dong][a.cot - 1] == 0 && truyvet[a.dong][a.cot - 1] == false)
		{
			TOADO s;
			s.dong = a.dong;
			s.cot = a.cot - 1;
			q.push(s); // Dua vao hang doi
			truyvet[s.dong][s.cot] = true; // Tai vi tri nay da duoc dua vao hang doi de chuan bi xet

			// Dieu kien dung khi vi tri toa do moi dua vao chinh la dich den
			if(s.dong == dong_end && s.cot == cot_end)
			{
				TimThay = true; // Danh dau lai la da tim thay duong di
				break; // Thoat khoi qua trinh lap va ket luan
			}
		}
	}
	if(TimThay == true)
		cout << "YES";
	else
		cout << "NO";

	FileIn.close();
	system("pause");
	return 0;
}

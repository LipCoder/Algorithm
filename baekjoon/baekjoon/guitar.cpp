// 끊어진 기타줄 N개 브랜드 M개
// 각각 브랜드에서 파는 키타줄 6개 가격
// 낱개로 살때의 가격
// 필요한 돈의 최소

#include <iostream>
#include <algorithm>
using namespace std;

struct price
{
	int package;
	int each;
};

bool cmp1(price& a, price& b)
{
	return a.package < b.package;
}

bool cmp2(price& a, price& b)
{
	return a.each < b.each;
}

int main()
{
	int guitarLine;
	int brands;

	cin >> guitarLine >> brands;

	price* priceInfo = new price[brands];

	for (int i = 0; i < brands; ++i)
	{
		cin >> priceInfo[i].package >> priceInfo[i].each;
	}

	// 패키지 가격 오름차순 정렬
	sort(priceInfo, priceInfo + brands, cmp1);
	int minPackage = priceInfo[0].package;
	// 낱개 가격 오름차순 정렬
	sort(priceInfo, priceInfo + brands, cmp2);
	int minEach = priceInfo[0].each;

	int result = 0;

	// 6줄이 넘는 경우
	if (6 <= guitarLine)
	{
		// 낱개로 사는게 패키지 가격보다 비싼 경우
		if (6 * minEach > minPackage)
		{
			// 패키지로 산다.
			result += (guitarLine / 6) * minPackage;
			guitarLine %= 6;
		}
		else
		{
			// 낱개로 산다.
			result += guitarLine * minEach;
			guitarLine = 0;
		}
	}

	// 패키지로 사고 사야할 기타줄 수가 남거나
	// 혹은 사야할 기타줄 수가 6줄 보다 작은 경우
	if (0 < guitarLine)
	{
		// 낱개로 사는게 패키지 가격보다 비싼 경우
		if (guitarLine * minEach > minPackage)
			result += minPackage;
		else
			result += guitarLine * minEach;
	}

	cout << result << endl;
	delete[] priceInfo;
}
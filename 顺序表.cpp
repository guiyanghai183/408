#define MaxSize 50
#define InitSize 100

typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;

//插入操作O(n)
bool ListInsert(SqList &L, int i, ElemType e)
{
	//边界情况
	if (i < 1 || i > L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= 1; j -- ) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length ++ ;             //线性表的长度加1
	return true;
}

//删除操作O(n)
bool ListDelete(Sqlist &L, int i, Elemtype &e)
{
	if (i < 1 || i > L.length)
		return false;
	e = L.data[i - 1];
	for (int j = i; j < L.length; j ++ )
		L.data[j - 1] = L.data[j];
	L.length -- ;
	return true;
}

//查找操作O(n)
int LocateElem(Sqlist &L, Elemtype &e)
{
	int i;
	for (int i = 0; i < L.length; i ++ )
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

//综合应用题

//1-1 O(n)
bool Del_Min(Sqlist &L, ElemType &e)
{
	//删除顺序表L中的最小值结点，并通过引用型参数e返回具体值
	if (i < 1 || i > L.length)
		return false;

	min_num = L[0], pos = 0;                // 假定0号元素最小
	for (int i = 0; i < L.length; i ++ ) {
		/*
		if(L.data[i] < min_num)
		{
			min_num = L.data[i];
			pos = i;
		}
		*/
min_num = min_num <= L.data[i] :
		          min_num ? (L.data[i], pos = i);
	}
	L.data[pos] = L.data[L.length - 1];

	L.length -- ;

	return true;
}

//1-2 O(n)
void Revrse_List(Sqlist &L)
{
	//双指针算法
	int l = 0, r = L.length - 1;
	while (l < r) {
		ElemType t;
		t = L.data[l];
		L.data[l ++ ] = L.data[r];
		L.data[r -- ] = t;
	}
}

//王道解析
void Reverse(Sqlist &L)
{
	ElemType temp;
	for (int i = 0; i < L.length / 2; i ++ ) {
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

//1-3 O(n)
void Del_x(SqList &L, ElemType &e)
{
	int k = 0;
	for (int i = 0; i < L.length; i ++ ) {
		if (L.data[i] != x)
			L.data[k ++ ] = L.data[i]; //data不为k的复制元素
		L.length = k;
	}
}


//(难想到)
void Del_x(SqList &L, ElemType &e)
{
	int k = 0;
	for (int i = 0; i < L.length; i ++ )
		if (L.data[i] == x)
			k ++ ;             //k的值记录等于x元素的个数
		else {
			L.data[i - k] = L.data[i]; //当前元素前移k个位置
		}
	L.length = L.length - k;

}

//1-4 O(n)
//测试可行
bool Del_range(SqList &L, ElemType s, ElemType t)
{
	if (s >= t)
		return false;

	int k = 0;
	for (int i = 0; i < L.length; i ++ )
		if (L.data[i] < s || L.data[i] > t)
			L.data[k ++ ] = L.data[i];

	L.length = k;
	if (L.length == 0)
		return false;

	return true;
}

//王道解法O(n)
bool Del_s_t2(SqList &L, ElemType s, ElemType t)
{
	//实际上我觉得判断是否为空，可以放在最后判断length
	int i, j;
	if (s >= t || L.length == 0)
		return false;
	for (i = 0; i < L.length && L.data[i] < s; i ++ ) //寻找第一个大于等于s的值
		if (i >= L.length)
			return false;
	for (j = i; j < L.length && L.data[j] <= t; j ++ ) //寻找第一个大于t的值

		for (; j < L.length; i ++, j ++ )
			L.data[i] = L.data[j];
	L.length = i;
	return true;
}

//1-5 同1-3
bool Del_range(SqList &L, ElemType s, ElemType t)
{
	if (s >= t)
		return false;

	int k = 0;
	for (int i = 0; i < L.length; i ++ )
		if (L.data[i] < s || L.data[i] > t)
			L.data[k ++ ] = L.data[i];

	L.length = k;
	if (L.length == 0)
		return false;

	return true;
}

bool Del_s_t(SqList &L, ElemType s, ElemType t)
{
	int i, k = 0;
	if (L.length == 0 || s >= t)
		return false;
	for (i = 0; i < L.length; i ++ )
		if (L.data[i] >= s && L.data[i] <= t)
			k ++ ;
		else
			L.data[i - k] = L.data[i];
	L.length -= k;
	return true;
}

//1-6 O(n)
bool Del_rep(SqList &L)
{
	if (L.length == 0)
		return false;
	int k = 1;
	for (int i = 1; i < L.length; i ++ ) {
		if (L.data[i] != L.data[i - 1])
			L.data[k ++ ] = L.data[i];
	}

	L.length = k;
	return true;
}

//无序表
/*可能需要手写哈希表，查了一下，并不能使用标准库的算法*/

//1-7 典型归并操作 O(n)
bool Merge(SqList L1, SqList L2, SqList &L)
{
	if (L1.length + L2.length > L.length)
		return false;

	int i = 0, j = 0, k = 0;
	while (i < L1.length && j < L2.length)
		if (L1.data[i] < L2.data[j])
			L.data[k ++ ] = L1.data[i ++ ];
		else
			L.data[k ++ ] = L2.data[j ++ ];
	while (i < L1.length)
		L.data[k ++ ] = L1.data[i ++ ];
	while (j < L2.length)
		L.data[k ++ ] = L2.data[j ++ ];

	return true;
}

//1-8
/*
A[m + n] = [a1, a2, ..., am, b1, b2, ..., bn]
-> A[m + n] = [b1, b2, ..., bn, a1, a2, ..., am]
1 [bn, bn-1, ..., b1, am, am-1, ..., a1]
2 [b1, b2, ..., bn, a1, a2, ..., am]
*/
void List_change(int a[], int m, int n, int array_size)
{
	int i = 0, j = array_size - 1;
	while (i < j) { //原地逆置
		int tmp = a[i];
		a[i ++ ] = a[j];
		a[j -- ] = tmp;
	}

	i = 0, j = n - 1;
	while (i < j) {
		int tmp = a[i];
		a[i ++ ] = a[j];
		a[j -- ] = tmp;
	}

	i = n, j = m + n - 1;
	while (i < j) {
		int tmp = a[i];
		a[i ++ ] = a[j];
		a[j -- ] = tmp;
	}

}

//封装写法
void List_Change(int a[], int m, int n, int array_size)
{
	Reverse(a, 0, array_size - 1);
	Reverse(a, 0, n - 1);
	Reverse(a, n, m + n - 1);
}

void Reverse(int a[], int l, int r)
{
	int i = l, j = r;
	while (i < j) {
		int tmp = a[i];
		a[i ++ ] = a[j];
		a[j -- ] = tmp;
	}
}

//1-9 O(n)
bool List_insert(int L[], ElemType x, int n)
{
	// 二分查找最后一个小于等于x的数
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (L[mid] <= x)
			l = mid;
		else
			r = mid - 1;
	}

	if (L[l] == x) {
		int tmp = L[l];
		L[l] = L[l + 1];
		L[l + 1] = tmp;
	} else {
		for (int i = n - 1; i >= l; i -- )
			L[i + 1] = L[i];
		L[l] = x;
	}
}

//1-10(不会做什么玩意？？？)
/* 数组ab转换成数组ba
a代表数组的前p个元素
b代表数组中余下的n-p个元素
先将a逆置得到a^-1b 再将b逆置得到a^-1b^-1
再整体逆置(a^-1b^-1)^-1 = ba
*/

//O(n) O(1)
void Converse(int R[], int n, int p)
{
	Reverse(R, 0, p - 1);
	Reverse(R, p, n - 1);
	Reverse(R, 0, n - 1);
}

//1-11 O(n) O(1)
/*双指针i,j扫描递增有序表A,B,同时用t记录值较小的数量
用rlt存结果,当t = A.length + 1时表示中位数*/
ElemType L_2(SqList A, SqList B)
{
	int t = 0, i = 0, j = 0, rlt;
	while (i < A.length && j < B.length && t < A.length + 1) {
		if (A.data[i] < B.data[j])
			rlt = A.data[i], i ++  ;
		else
			rlt = B.data[j], j ++ ;
		t ++ ;
	}

	while (i < A.length && t < A.length + 1)
		rlt = A.data[i], i ++, t ++ ;
	while (j < B.length && t < B.length + 1)
		rlt = B.data[j], j ++, t ++ ;


	return rlt;
}

//王道解法 O(log2n) O(1)
/*分别求两个升序序列A、B的中位数，设为a,b
1 若 a = b 则 a 或 b为所求中位数
2 若 a < b 则舍弃A中较小的一半，B中较大的一半，要求两次舍弃的长度相等
3 若 a > b 则舍弃B中较小的一半, A中较大的一半，要求两次舍弃的长度相等
此选取方法保证了留下的中位数不变
重复过程1 2 3直到两个序列均只含一个元素为止，则较小者为所求中位数
*/
int M_Search(int A[], int B[], int n)
{
	int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
	//分别表示序列A和B的首位数、末位数和中位数
	while (s1 != d1 || s2 != d2) {
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if (A[m1] == B[m2])
			return A[m1];
		if (A[m1] < B[m2]) {
			if ((s1 + d1) % 2 == 0) //若元素个数为奇数
				s1 = m1;		   //舍弃A中间点以前的部分且保留中间点
			d2 = m2;           //舍弃B中间点以后的部分且保留中间点
			else {
				s1 = m1 + 1;       //舍弃A中间点及中间点以前的部分
				s2 = m2;		   //舍弃B中间点以后且保留中间点
			}
		} else {
			if ((s2 + d2) % 2 == 0) {
				d1 = m1;
				s2 = m2;
			} else {
				d1 = m1;
				s2 = m2 + 1;
			}
		}

	}

	return A[s1] < B[s2] ? A[s1] : B[s2];
}


// 1-13 O(n) O(1)
int search_min(int A[], int n)
{
	int min_num = -1;
	for (int i = 0; i < n; i ++ ) {
		if (A[i] <= 0)
			continue;
		min_num = (min_num == -1 || A[i] < min_num) ? A[i] : min_num;
	}
	return A[i] - 1;
}

//王道做法 O(n) O(n)
/*我认为王道做法有个缺陷，A[i]中数的上限不一定是n
B的size应该开到int的最大值
我的做法错了
*/
int findMissMin(int A[], int n)
{
	int i, *B; //标记shuzu
	B = (int *)malloc(sizeof(int) * n);
	memset(B, 0, sizeof(int) * n);
	for (int i = 0; i < n; i ++ )
		if (A[i] > 0 && A[i] <= n)
			B[A[i] - 1] = 1;
	for (int i = 0; i < n; i ++ )
		if (B[i] == 0)
			break;
	return i + 1;
}

//1-14
/*
找到A,B,C三个数组中的最小最大值
rlt = |a - b| + |b - a| + |a - c|
不妨设 a <= b <= c
rlt = 2（c - a)
*/
/*错误了，不能使用最大值-最小值，这样求得就是rlt的最大值了
int findMinofTrip(int A[], int n, int B[], int m, int C[], int p)
{
	int min_num = A[0], max_num = A[0];

	for (int i = 0; i < n; i ++ ) {
		min_num = (min_num < A[i]) ? min_num : A[i];
		max_num = (max_num > A[i]) ? max_num : A[i];
	}

	for (int i = 0; i < m; i ++ ) {
		min_num = (min_num < B[i]) ? min_num : B[i];
		max_num = (max_num > B[i]) ? max_num : B[i];
	}

	for (int i = 0; i < p; i ++ ) {
		min_num = (min_num < C[i]) ? min_num : C[i];
		max_num = (max_num > C[i]) ? max_num : C[i];
	}

	return 2 * (max_num - min_num);
}
*/

#define INT_MAX 0x7ffffff

int abs_(int a)

{
	if (a < 0)
		return -a;
	else
		return a;
}

bool xls_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return true;
	return false;
}

int findMinofTrip(int A[], int n, int B[], int m, int C[], int p)
{
	//D_min用于记录三元组的最小距离，初值赋为INT_MAX
	int i = 0, j = 0, k = 0, D_min = INT_MAX, D;
	while (i < n && j < m && p < D && D_min > 0) {
		D = abs_(A[i] - B[j]) + abs_(B[j] - C[k]) + abs_(C[k] - A[i]);
		if (D < D_min)
			D_min = D;
		if (xls_min(A[i], B[j], C[k]))
			i ++ ; //更新a
		else if (xls_min(B[j], C[k], A[i]))
			j ++ ;
		else
			k ++ ;
	}
	return D_min
}

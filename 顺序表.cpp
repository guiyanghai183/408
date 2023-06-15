#define MaxSize 50
#define InitSize 100

typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;

//�������O(n)
bool ListInsert(SqList &L, int i, ElemType e)
{
	//�߽����
	if (i < 1 || i > L.length + 1)
		return false;
	if (L.length >= MaxSize)
		return false;
	for (int j = L.length; j >= 1; j -- ) {
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;
	L.length ++ ;             //���Ա�ĳ��ȼ�1
	return true;
}

//ɾ������O(n)
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

//���Ҳ���O(n)
int LocateElem(Sqlist &L, Elemtype &e)
{
	int i;
	for (int i = 0; i < L.length; i ++ )
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

//�ۺ�Ӧ����

//1-1 O(n)
bool Del_Min(Sqlist &L, ElemType &e)
{
	//ɾ��˳���L�е���Сֵ��㣬��ͨ�������Ͳ���e���ؾ���ֵ
	if (i < 1 || i > L.length)
		return false;

	min_num = L[0], pos = 0;                // �ٶ�0��Ԫ����С
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
	//˫ָ���㷨
	int l = 0, r = L.length - 1;
	while (l < r) {
		ElemType t;
		t = L.data[l];
		L.data[l ++ ] = L.data[r];
		L.data[r -- ] = t;
	}
}

//��������
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
			L.data[k ++ ] = L.data[i]; //data��Ϊk�ĸ���Ԫ��
		L.length = k;
	}
}


//(���뵽)
void Del_x(SqList &L, ElemType &e)
{
	int k = 0;
	for (int i = 0; i < L.length; i ++ )
		if (L.data[i] == x)
			k ++ ;             //k��ֵ��¼����xԪ�صĸ���
		else {
			L.data[i - k] = L.data[i]; //��ǰԪ��ǰ��k��λ��
		}
	L.length = L.length - k;

}

//1-4 O(n)
//���Կ���
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

//�����ⷨO(n)
bool Del_s_t2(SqList &L, ElemType s, ElemType t)
{
	//ʵ�����Ҿ����ж��Ƿ�Ϊ�գ����Է�������ж�length
	int i, j;
	if (s >= t || L.length == 0)
		return false;
	for (i = 0; i < L.length && L.data[i] < s; i ++ ) //Ѱ�ҵ�һ�����ڵ���s��ֵ
		if (i >= L.length)
			return false;
	for (j = i; j < L.length && L.data[j] <= t; j ++ ) //Ѱ�ҵ�һ������t��ֵ

		for (; j < L.length; i ++, j ++ )
			L.data[i] = L.data[j];
	L.length = i;
	return true;
}

//1-5 ͬ1-3
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

//�����
/*������Ҫ��д��ϣ������һ�£�������ʹ�ñ�׼����㷨*/

//1-7 ���͹鲢���� O(n)
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
	while (i < j) { //ԭ������
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

//��װд��
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
	// ���ֲ������һ��С�ڵ���x����
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

//1-10(������ʲô���⣿����)
/* ����abת��������ba
a���������ǰp��Ԫ��
b�������������µ�n-p��Ԫ��
�Ƚ�a���õõ�a^-1b �ٽ�b���õõ�a^-1b^-1
����������(a^-1b^-1)^-1 = ba
*/

//O(n) O(1)
void Converse(int R[], int n, int p)
{
	Reverse(R, 0, p - 1);
	Reverse(R, p, n - 1);
	Reverse(R, 0, n - 1);
}

//1-11 O(n) O(1)
/*˫ָ��i,jɨ����������A,B,ͬʱ��t��¼ֵ��С������
��rlt����,��t = A.length + 1ʱ��ʾ��λ��*/
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

//�����ⷨ O(log2n) O(1)
/*�ֱ���������������A��B����λ������Ϊa,b
1 �� a = b �� a �� bΪ������λ��
2 �� a < b ������A�н�С��һ�룬B�нϴ��һ�룬Ҫ�����������ĳ������
3 �� a > b ������B�н�С��һ��, A�нϴ��һ�룬Ҫ�����������ĳ������
��ѡȡ������֤�����µ���λ������
�ظ�����1 2 3ֱ���������о�ֻ��һ��Ԫ��Ϊֹ�����С��Ϊ������λ��
*/
int M_Search(int A[], int B[], int n)
{
	int s1 = 0, d1 = n - 1, m1, s2 = 0, d2 = n - 1, m2;
	//�ֱ��ʾ����A��B����λ����ĩλ������λ��
	while (s1 != d1 || s2 != d2) {
		m1 = (s1 + d1) / 2;
		m2 = (s2 + d2) / 2;
		if (A[m1] == B[m2])
			return A[m1];
		if (A[m1] < B[m2]) {
			if ((s1 + d1) % 2 == 0) //��Ԫ�ظ���Ϊ����
				s1 = m1;		   //����A�м����ǰ�Ĳ����ұ����м��
			d2 = m2;           //����B�м���Ժ�Ĳ����ұ����м��
			else {
				s1 = m1 + 1;       //����A�м�㼰�м����ǰ�Ĳ���
				s2 = m2;		   //����B�м���Ժ��ұ����м��
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

//�������� O(n) O(n)
/*����Ϊ���������и�ȱ�ݣ�A[i]���������޲�һ����n
B��sizeӦ�ÿ���int�����ֵ
�ҵ���������
*/
int findMissMin(int A[], int n)
{
	int i, *B; //���shuzu
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
�ҵ�A,B,C���������е���С���ֵ
rlt = |a - b| + |b - a| + |a - c|
������ a <= b <= c
rlt = 2��c - a)
*/
/*�����ˣ�����ʹ�����ֵ-��Сֵ��������þ���rlt�����ֵ��
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
	//D_min���ڼ�¼��Ԫ�����С���룬��ֵ��ΪINT_MAX
	int i = 0, j = 0, k = 0, D_min = INT_MAX, D;
	while (i < n && j < m && p < D && D_min > 0) {
		D = abs_(A[i] - B[j]) + abs_(B[j] - C[k]) + abs_(C[k] - A[i]);
		if (D < D_min)
			D_min = D;
		if (xls_min(A[i], B[j], C[k]))
			i ++ ; //����a
		else if (xls_min(B[j], C[k], A[i]))
			j ++ ;
		else
			k ++ ;
	}
	return D_min
}

#include<iostream>
using namespace std;
//��ʱ
//int divide(int dividend, int divisor){
//	int count = 0;
//	if(dividend >= 0 && divisor > 0){
//		while(dividend >= divisor){
//			dividend -= divisor;
//			if(count + 1 < INT_MAX)
//				count++;
//			else
//				return INT_MAX;
//			if(dividend < divisor)
//				return count;
//		}
//	}
//	else if(dividend <= 0 && divisor < 0){
//		while(dividend <= divisor){
//			dividend -= divisor;
//			if(count + 1 < INT_MAX)
//				count++;
//			else
//				return INT_MAX;
//			if(dividend > divisor)
//				return count;
//		}
//	}
//	else if(dividend >= 0 && divisor < 0){
//		while(dividend >= divisor){
//			dividend += divisor;
//			if(count - 1 > INT_MIN)
//				count--;
//			else
//				return INT_MAX;
//			if(dividend < divisor)
//				return count+2;
//		}
//	}
//	else{
//		while(dividend <= divisor){
//			dividend += divisor;
//			if(count - 1 > INT_MIN)
//				count--;
//			else
//				return INT_MAX;
//			if(dividend > divisor)
//				return count+2;
//		}
//	}
//	return count;
//}
int divi(long a, long b){
        if(a < b) 
			return 0;
        long count = 1;
        long tb = b;
        while((tb + tb) <= a){
            count = count + count;
            tb = tb + tb;
        }//���Ƴ���������
        return count + divi(a - tb,b);
    }
    int divide(int dividend, int divisor) {
        if(dividend == 0) 
			return 0;
        if(divisor == 1) 
			return dividend;
        if(divisor == -1){
            if(dividend > INT_MIN) 
				return -dividend;// ֻҪ������С���Ǹ�����������ֱ�ӷ����෴���ͺ���
            return INT_MAX;// ����С���Ǹ����Ǿͷ�������������
        }
        long a = dividend;
        long b = divisor;
        bool flag = false; 
        if((a > 0 && b < 0) || (a < 0 && b > 0))
            flag = true;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long res = divi(a,b);
        if(!flag)
			return res > INT_MAX ? INT_MAX : res;
        return -res;
    }
int main(){
	int dividend,divisor;
	cin >> dividend >> divisor;
	cout << divide(dividend,divisor) << endl;
	system("pause");
	return 0;
}
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// ===============Bài 1 đảo mảng 1 chiều=================
/*
void ReverseArray(int array[],int n){
    for(int i=0;i<n/2;i++){
        int temp = array[i];
        array[i]=array[n-i-1];
        array[n-i-1]=temp;
    }
}
// cách 2 dùng pointer
void ReverseArrayPtr(int array[], int n) {
    int *left = array;           // trỏ vào phần tử đầu
    int *right = array + n - 1;  // trỏ vào phần tử cuối

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;   // tiến về giữa
        right--;  // lùi về giữa
    }
}
int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    ReverseArray(a,n);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}*/
// ===============Bài 2 Rotate Array=====================
/*void RotateArray(int array[],int n,int k){
    while(k--){
        int last = array[n-1];
        for(int i=n-1;i>0;i--){
            array[i]=array[i-1];
        }
        array[0]=last;

    }
}
int main(void){
    int n,k;
    scanf("%d%d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    RotateArray(a,n,k);
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;

}
*/

//================Bài 3 Find max subarray sum============
/*void FindMax(int array[],int n){
    int max_sum = array[0];
    int current_sum = array[0];
    int start = 0,temp_star=0,end=0;
    for(int i=1;i<n;i++){
        if(current_sum + array[i]<array[i]){
            current_sum=array[i];
            temp_star=i;
        }else{
            current_sum+=array[i];
        }
        if(current_sum>max_sum){
            max_sum=current_sum;
            start=temp_star;
            end=i;
        }
    }
    printf("Max = %d\n",max_sum);
    for(int i=start; i<=end; i++){
        printf("%d ",array[i]);
    }
    printf("\n");
}
int main(void){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    FindMax(a,n);
    return 0;

}
*/

//================Bài 4 Array + Union====================

//Mục tiêu:
//Biết cách dùng union để đọc bit pattern của float.
//Copy từng byte float vào mảng uint8_t buffer[N] → truyền UART/I2C.
//Thực hành tư duy bitwise + array.

//Ý tưởng
//Tạo union float ↔ uint32_t.
//Gán giá trị float (ví dụ f = 3.14).
//Dùng unsigned char* hoặc mảng uint8_t buffer[4] để lưu từng byte.
//In từng byte ra hex → kiểm tra bit pattern.

union FloatUnion{
    float f;
    uint32_t u;
};
int main(void){
    union FloatUnion fu;
    fu.f = 3.14;
    // mảng byte chứa dữ liệu float
    uint8_t buffer[sizeof(fu)];
    //copy bit pattern vào buffer
    memcpy(buffer,&fu,sizeof(fu));
    // In float
    printf("Float value: %f\n", fu.f);
    printf("kich thuoc : %zu\n", sizeof(fu));
    // In từng byte hex
    printf("Bytes: ");
    for(int i = 0; i < sizeof(buffer); i++)
        printf("%02X ", buffer[i]);
    printf("\n");
    return 0;   
}
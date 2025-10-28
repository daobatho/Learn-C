#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>
// ====================Bài 1 In thông tin kiểu dữ liệu=================================
/*
 * Mục tiêu:
 *  - Kiểm tra kích thước (sizeof) và giới hạn (min/max) của tất cả kiểu dữ liệu cơ bản trong C.
 *  - Rất hữu ích khi lập trình nhúng, vì kích thước kiểu có thể khác nhau giữa các vi điều khiển hoặc hệ thống.
 *
 * Thư viện:
 *  <limits.h> : chứa các hằng số giới hạn của kiểu số nguyên (INT_MIN, LONG_MAX, ...).
 *  <float.h>  : chứa các hằng số giới hạn của kiểu số thực (FLT_MIN, DBL_MAX, ...).
 */

/*
int main(void) {

    printf("===== KIEU DU LIEU NGUYEN (Integer Types) =====\n\n");

    // Kiểu ký tự 1 byte, có thể signed hoặc unsigned tùy compiler
    printf("char:               %zu byte | signed: %d to %d | unsigned: 0 to %u\n",
           sizeof(char), SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);

    // Kiểu short integer (thường 2 byte)
    printf("short:              %zu byte | signed: %d to %d | unsigned: 0 to %u\n",
           sizeof(short), SHRT_MIN, SHRT_MAX, USHRT_MAX);

    // Kiểu int (thường 4 byte, là kiểu mặc định khi khai báo số nguyên)
    printf("int:                %zu byte | signed: %d to %d | unsigned: 0 to %u\n",
           sizeof(int), INT_MIN, INT_MAX, UINT_MAX);

    // Kiểu long (4 byte trên Windows, 8 byte trên Linux/macOS 64-bit)
    printf("long:               %zu byte | signed: %ld to %ld | unsigned: 0 to %lu\n",
           sizeof(long), LONG_MIN, LONG_MAX, ULONG_MAX);

    // Kiểu long long (ít nhất 8 byte, đảm bảo biểu diễn số nguyên rất lớn)
    printf("long long:          %zu byte | signed: %lld to %lld | unsigned: 0 to %llu\n\n",
           sizeof(long long), LLONG_MIN, LLONG_MAX, ULLONG_MAX);

    printf("===== KIEU DU LIEU THUC (Floating-Point Types) =====\n\n");

    // Kiểu float (32-bit IEEE 754), chính xác ~6 chữ số thập phân
    printf("float:              %zu byte | range: %e to %e | precision: %d digits\n",
           sizeof(float), FLT_MIN, FLT_MAX, FLT_DIG);

    // Kiểu double (64-bit IEEE 754), chính xác ~15 chữ số thập phân
    printf("double:             %zu byte | range: %e to %e | precision: %d digits\n",
           sizeof(double), DBL_MIN, DBL_MAX, DBL_DIG);

    // Kiểu long double (80–128-bit tùy hệ thống), chính xác ~18 chữ số
    printf("long double:        %zu byte | range: %Le to %Le | precision: %d digits\n\n",
           sizeof(long double), LDBL_MIN, LDBL_MAX, LDBL_DIG);

    printf("===== CAC KIEU KHAC (Bo sung) =====\n\n");

    // Kiểu boolean trong C99 (_Bool chỉ nhận 0 hoặc 1)
    printf("_Bool (bool):       %zu byte | range: 0 or 1\n", sizeof(_Bool));

    // Kiểu size_t: unsigned, dùng cho kích thước mảng, kết quả sizeof()
    printf("size_t:             %zu byte | unsigned only (dung cho kich thuoc)\n", sizeof(size_t));

    // Kiểu ptrdiff_t: signed, dùng cho phép trừ hai con trỏ
    printf("ptrdiff_t:          %zu byte | signed (chenh lech giua 2 con tro)\n", sizeof(ptrdiff_t));

    // Kiểu con trỏ void*: chứa địa chỉ bộ nhớ (kích thước phụ thuộc hệ thống: 4 hoặc 8 byte)
    printf("void * (pointer):   %zu byte | dia chi bo nho (phu thuoc kieu he thong)\n", sizeof(void*));

    return 0;
}
*/

// =======================Bài 2 Tính số bit của kiểu dữ liệu=============================
/*
 * Mục tiêu: Hiểu mối liên hệ byte ↔ bit.
 * Yêu cầu:
 * Tính và in ra số bit cho từng kiểu:
 */
/*int main(void) {
    printf("===== TINH SO BIT CUA CAC KIEU DU LIEU =====\n\n");

    printf("char:        %zu byte  = %zu bits\n", sizeof(char), sizeof(char) * CHAR_BIT);
    printf("short:       %zu byte  = %zu bits\n", sizeof(short), sizeof(short) * CHAR_BIT);
    printf("int:         %zu byte  = %zu bits\n", sizeof(int), sizeof(int) * CHAR_BIT);
    printf("long:        %zu byte  = %zu bits\n", sizeof(long), sizeof(long) * CHAR_BIT);
    printf("long long:   %zu byte  = %zu bits\n", sizeof(long long), sizeof(long long) * CHAR_BIT);
    printf("float:       %zu byte  = %zu bits\n", sizeof(float), sizeof(float) * CHAR_BIT);
    printf("double:      %zu byte  = %zu bits\n", sizeof(double), sizeof(double) * CHAR_BIT);
    printf("long double: %zu byte  = %zu bits\n", sizeof(long double), sizeof(long double) * CHAR_BIT);

    return 0;
}
*/

// ================Bài 3 kiểm tra overflow & underflow trong số nguyên=====================
/*
int main(void) {
    printf("===== SIGNED INT =====\n");
    int a = INT_MAX;
    printf("INT_MAX = %d\n", a);
    a = a + 1;
    printf("After overflow (INT_MAX + 1): %d\n\n", a);
    int b = INT_MIN;
    printf("INT_MIN = %d\n", b);
    b = b - 1;
    printf("After underflow (INT_MIN - 1): %d\n\n", b);
    printf("===== UNSIGNED INT =====\n");
    unsigned int ua = UINT_MAX;
    printf("UINT_MAX = %u\n", ua);
    ua = ua + 1;
    printf("After overflow (UINT_MAX + 1): %u\n\n", ua);
    unsigned int ub = 0;
    printf("UINT_MIN = %u\n", ub);
    ub = ub - 1;
    printf("After underflow (0 - 1): %u\n", ub);
    return 0;
}
*/

//=================================Bài 4 ép kiểu=========================================

/*
int main(void){
       
       //Ý tưởng:
       //float lưu được phần thập phân (ví dụ 12.75)
       //Khi ép sang int, chỉ giữ phần nguyên, bỏ phần thập phân.
       float pi =3.14;
       int x=(int)pi;
       printf("gia tri ban dau f = %.2f",pi);
       printf("\ngia tri sau khi ep = %d\n",x);
       // Ý tưởng:
       // long long có thể lưu giá trị rất lớn (64-bit)
       // short chỉ có 16-bit → nếu giá trị vượt giới hạn ±32767, sẽ bị tràn dữ liệu (overflow).
       
      long long big = 70000 ; // vượt phạm vi short
      short s = (short)big ;
      printf("Gia tri goc : %lld\n", big);
      printf("Gia tri sau khi ep : %d\n", s);
      printf("Pham vi short %d to %d\n", SHRT_MIN, SHRT_MAX);
       
      //Ý tưởng:
       //unsigned int không lưu số âm, chỉ biểu diễn giá trị từ 0 → 2³²−1 (trên hệ thống 32-bit).
       //Khi bạn gán số âm cho biến unsigned, C chuyển đổi modulo 2³² → wrap-around.
       
      unsigned int u = -10; // gán số âm cho unsigned
      printf("Gia tri -10 khi ep sang unsigned int: %u\n", u);
      printf("0x%X (dang hex)\n", u);

      int a = -10;
      unsigned int b = (unsigned int)a;

      printf("Gia tri int goc: %d\n", a);
      printf("Sau khi ep sang unsigned int: %u\n", b);
      printf("Dang hex: 0x%X\n", b);
       //Ý tưởng:
       //double có độ chính xác 15 chữ số, float chỉ có 6 chữ số.
       //Khi ép kiểu, phần mantissa bị cắt → mất chính xác.
      double d = 123456789.123456789;
      float f = (float)d;
      printf("Gia tri double goc : %.9f\n", d);
      printf("Sau khi ep sang float: %.9f\n", f);
      printf("Precision double = %d digits\n", DBL_DIG);
      printf("Precision float  = %d digits\n", FLT_DIG);
      return 0;
}
*/
/*
#include <stdio.h>
#include <stdint.h>

// Hàm in nhị phân kiểu int
void printBitsInt(int x) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if(i % 8 == 0) printf(" "); // cho dễ đọc
    }
    printf("\n");
}

// Hàm in nhị phân kiểu unsigned int
void printBitsUInt(unsigned int x) {
    for(int i = 31; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if(i % 8 == 0) printf(" ");
    }
    printf("\n");
}

// Hàm in nhị phân kiểu short
void printBitsShort(short x) {
    for(int i = 15; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
        if(i % 8 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    short s = -10;
    int i_signed = (int)s;            // ép signed short → int
    unsigned int i_unsigned = (unsigned int)(uint16_t)s; // ép unsigned short → int

    printf("Original short s = %d\n", s);
    printf("Bits of short s:          "); printBitsShort(s);

    printf("\nSigned extension to int:  %d\n", i_signed);
    printf("Bits of signed int:       "); printBitsInt(i_signed);

    printf("\nUnsigned extension to int: %u\n", i_unsigned);
    printf("Bits of unsigned int:     "); printBitsUInt(i_unsigned);

    return 0;
}

*/

// ==================Bài 5 Biểu diễn nhị phân số nguyên =================================
/*
// Mục tiêu
// Hiểu cách biểu diễn số nguyên (int, unsigned int) trong nhị phân.
// Quan sát bit pattern, wrap-around, số âm (two’s complement).
// Rèn luyện thao tác bitwise (&, >>, <<).

// Ý tưởng
// Chọn kiểu dữ liệu (ví dụ uint32_t hoặc int32_t).
// Duyệt từng bit (từ bit cao nhất → thấp nhất).
// Dùng toán tử bitwise AND & để kiểm tra bit:
void printBits(uint32_t x){
       for(int i=31;i>=0;i--){
              printf("%d",(x>>i)&1);
              if(i%8==0) printf(" ");
       }
       printf("\n");
}
int main(void){
       int a = -10;
       printBits(a);
       unsigned int b = (unsigned int)a;
       printBits(b);
       unsigned int c = 300;
       printBits(c);
       float d = 3.14;
       printBits(*(uint32_t *)&d);
}
*/

// ====================Bài 6 kiểm tra Endianness =================
/*
int main(void){
    unsigned int x = 0x01020304;
    unsigned char *p = (unsigned char *)&x;
    printf("Byte dau tien x = 0x%X\n", p[0]);
    if(p[0] == 0x01)
        printf("He thong: Big endian\n");
    else if(p[0] == 0x04)
        printf("He thong: Little endian\n");
    else
        printf("He thong: Không xác định\n");

    return 0;
}*/
 
// ============================ 7 Union hiển thị vùng nhớ=============================
/*
// Mục tiêu: Hiểu union → các thành phần chia sẻ cùng 1 vùng nhớ.
// Ý tưởng
// Tạo union giữa float và uint32_t
// Gán f = 3.14
// Đọc uint32_t → xem bit pattern của float
// In từng byte ra hex → thấy representation của float theo IEEE 754.

union FloatUnion{
       float f;
       uint32_t u;
};
int main(void){
       union FloatUnion fu;
       fu.f =3.14;
       printf("f = %f\n",fu.f);
       printf("hex : 0x%08X\n",fu.u);
       unsigned char *p = (unsigned char *)&fu;
       printf("Bytes :");
       for(int i=0; i<sizeof(fu);i++){
              printf("0x%02X\n",p[i]);
       }
       printf("\n");
       return 0;
       //Union → tất cả thành phần chung vùng nhớ
       //fu.u → đọc nguyên bit pattern float
       //Byte order sẽ phản ánh endianness → trực quan debug Embedded.
}
*/

// ===========================Bài 8 Struct alignment & padding========================

// Mục tiêu: Hiểu alignment và padding, tại sao struct có thể lớn hơn tổng kích thước các thành phần.
// Ý tưởng
// Tạo struct với các biến char, int, short
// Thứ tự khai báo ảnh hưởng padding → sizeof(struct) thay đổi
// Dùng __attribute__((packed)) → tắt padding.
struct S1 {
    char c;
    int i;
    short s;
};

struct S2 {
    int i;
    short s;
    char c;
};

struct __attribute__((packed)) S3 {
    char c;
    int i;
    short s;
};

int main(void) {
    printf("sizeof(S1) = %zu\n", sizeof(struct S1));
    printf("sizeof(S2) = %zu\n", sizeof(struct S2));
    printf("sizeof(S3, packed) = %zu\n", sizeof(struct S3));
    return 0;
    //Logic tư duy
    //CPU thường căn chỉnh dữ liệu theo word boundary → padding
    //Thứ tự khai báo ảnh hưởng vị trí và kích thước struct
    //packed → tắt padding, tiết kiệm bộ nhớ (nhưng có thể chậm hơn trên CPU).
}
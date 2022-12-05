#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("+==============Thong tin vaccine==============+\n");
	int soLuong, max, min;
	printf("Moi nhap so luong vacccine ");
	scanf("%d", &soLuong);
	int vaccine[soLuong];//các bạn nên gán số lượng vào đây luôn thì nó sẽ đúng
						// thực tế hơn cũng không mất ram của cpu .
	//nhập mảng !!
	for (int i = 0; i < soLuong; i++) {
		printf("Moi nhap mang so luong vaccine thu #%d ",(i + 1));
		//(i+1) ở đây là chỉ lừa cpu để cho nó đi từ 1 nhưng thật ra vẫn chạy từ 0.
		scanf("%d", &vaccine[i]);
	}
	
	printf("+=============== Xuat thong tin vaccine ===============+\n");
	printf("So luong vaccine la: %d\n", soLuong);
	
	// xuat mang !!
	for (int i = 0; i < soLuong; i++) 
		printf("%d  ", vaccine[i]);
		
	
	max = vaccine[0];
	min = vaccine[0];
	//sau khi nhap mảng xong mới được gán mãx,min nếu không nhiều trường hợp 
	// lấy giá trị rác !!
	//==================================================
	// day la phan tinh toan !!
	// chỗ này lấy i chạy từ 1 mà không phải la 0 vì
	// mình đã gán giá trị mãx,min là thằng đầu tiên rồi nên chỉ cần 
	//so sánh với thằng đứng trước nó chẳng ai lại đi hỏi lại mình có lớn hay bé hơn 
	//mình không cả !! 
	for (int i = 1; i < soLuong; i++) {
		if (vaccine[i] > max) max = vaccine[i];//nếu m lớn hơn tao thì m là max !!
		if (vaccine[i] < min) min = vaccine[i];//nếu m bé hơn m là min !! thế thôi!!
	}
	printf("\nThoi gian hieu qua thap nhat la %d \n", min);
	printf("Thoi gian hieu qua cao nhat la %d \n", max);
	
	//phần tiếp này là sắp xếp mảng 
	//phần này sẽ chạy 2 vòng for lồng nhau gọi là for trong for 
	//đừng nghĩ quá phức tạp bản chất nó là vòng for  trong 
	//thực hiện lại nhiều lần thôi để tối ưu hơn
	//nếu không ấy 2 vòng for thì ta phải làm từ vòng for thứ 0 .....N.
	//Như thế sẽ rất mất thời gian!!
	int tmp; //đây là biến trung gian để lưu trữ biến tạm thời thôi !!
	for (int i = 0; i < soLuong-1; i++)	
		for (int j = i+1; j < soLuong; j++)
			if (vaccine[i] < vaccine[j] )  
			   {
			   	tmp = vaccine[i];
			   	vaccine[i] = vaccine[j];
			   	vaccine[j] = tmp;
			   	// Thuật toán hoán đổi phần này cũng khá là khó mà lại cũng dễ!!
			   	// phần này có thể tìm max min luôn nhưng mình chia ra làm 2 
			   	// cho bạn dễ hình dung chúng ta nên đi từ từ. đừng vội!! 
				}
	printf("\nThoi gian hieu qua vaccine theo muc do giam dan :\n");
	for (int i = 0; i < soLuong; i++)	
		printf("%d  ", vaccine[i]);
	//hết bài !! chúc các bạn 10 điểm.
	return 0;
}
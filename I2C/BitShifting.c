#include <stdio.h>

int main() {
	int num = 62599; // 1111010010000111
	int data[2]; // 2 bytes
	int i, result;
	
	printf("num: %d\n", num);
	
	/*
		0xFF -> 255 -> 11111111
	*/
	
	data[0] = num >> 8; // Left Shift
	/*
		1111010010000111 (62599)
		0000000011110100 (244)
	*/
	
	data[1] = num & 0xFF;
	/*
		1111010010000111 (62599)
				&
		0000000011111111 (255)	
		0000000010000111 (135)
	*/
	
	printf("data[0]: %d, data[1]: %d\n", data[0], data[1]);
	
	result = data[0];
	/*
		0000000011110100 (244)
	*/
	
	result = (result << 8) | data[1]; // Right Shift
	/*
		0000000011110100 (244)
		<< 8
		1111010000000000 (62464)
				| 
		0000000010000111 (135)
		1111010010000111 (62599)
	*/
	printf("result: %d", result);
	
	return 0;
}

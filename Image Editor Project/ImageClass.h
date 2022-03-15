//Lavani Somesan
#ifndef IMAGECLASS_H
#define IMAGECLASS_H


class ChangeImage {

	public:
	//Functions
	void Rotate90(int imArr[][24], const int row, const int column);
	void Rotate180(int imArr[][24], int row, int column);
	void Rotate270(int imArr[][24], int row, int column);
	void VerticalFlip(int imArr[][24], int row, int column);
	void HorizontalFlip(int imArr[][24], int row, int column);
	void BlackAndWhite(int imArr[][24], int row, int column, int thresh);




};



#endif

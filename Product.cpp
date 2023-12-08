#include <iostream>
#include <string>

using namespace std; 

struct Product
{
	string name; // ten san pham  
	int price; // giá san pham  
	int quantity; // so luong san pham  
	
	friend istream& operator>>(istream &is, Product &product)
	{
		cout <<"Nhap ten: ";
		is.ignore(); 
		getline(is, product.name); 
		cout <<"Nhap gia san pham: ";
		cin >> product.price; 
		cout <<"Nhap so luong: ";
		cin >> product.quantity;  
		
		return is;  
	 } 
	
	friend ostream& operator<<(ostream &os, Product product)
	{
		os << "Ten: " << product.name << endl ;
		os << "Gia: " << product.price<< endl; 
		os << "So luong: "<< product.quantity<< endl; 
		 
		return os;  
	 } 
	
};
 
int show_menu();// hien thi ra menu 
void print_product(Product *product, int size); // xem danh sách 
void add_product(Product* &product, int &size ); // them san pham  
void delete_product(Product* &product, int &size); //xoa san pham  


int main ()
{
	int size = 0; 
	// khai bao con tro de quan lí san pham 
	Product *product = new Product[size];  
 	// trong chuong trinh, khi su dung lap di lap lai nên chon while 
	while (true)
	{
		int chose = show_menu(); 
		
		system("cls");  
		// xu ly cac lua cho dung switch case
		switch( chose )
		{
			case 1:
			// xem danh sach
				print_product(product, size) ; 
				break;  
			
			case 2: 
			// them san oham 
				add_product(product, size);  
				break; 
			 
			case 3: 
			// xoa san pham
				delete_product(product, size);  
				break;  
				
			case 0:  
				cout <<" Bye! "; 
				return 0; 
				 
			default:  
				cout << "Lua chon khong hop le." << endl;  
		} 
		
		cout << "Ban có muon tiep tuc khong? (1/0) "; 
		// tao bien bool de cho nguoi dung muon tiep tuc hay khong 
		bool is_continue; 
		cin >> is_continue; 
		
		// vi while true chay vo han nen ta xet diêu kien 
		// neu khong tiep tuc  (!is_continue)  
		if (!is_continue )
		{
			cout << "Bye Bye mai nhe!";
			break;   
		}
	} 
 	
 	return 0  ;
} 

int show_menu()
{
	
	system("cls "); // len nay xoa du lieu hien thi tren man hinh console  
	int chose; 
	cout << "===== Menu ====="<<endl; 
	cout << "1. Xem danh sach san pham "<< endl; 
	cout << "2. Them san pham moi "<< endl; 
	cout << "3. Xoa san pham "<<endl; 
	cout << "0. Thoat chuong trinh "<< endl; 
	
	cout << " Lua chon cua ban la: "; 
	
	// nhap so nguyen de chon 3 lua chon ten  
	cin >> chose; 
	
	return chose;  
} 

//ham in  san pham  
void print_product(Product *product, int size)
{
	if (!size)
	{ 
		cout << "Chua co san pham nao :3" << endl;  
	} 
	else 
	{
		cout << "Danh sach san pham: " << endl; 
		
		for( int i = 0; i < size; i++ )
		{
			cout << product[i] ; 
		}
	 } 
}


//ham them san pham  
void add_product(Product* &product, int &size )
{
	//tao san pham moi 
	Product new_product; 
	cout << "Nhap thong tin san pham moi: "<< endl; 
	cin >> new_product;  
	
	//them san pham vao cuoi mang
	//dau tien tao mang tam 
	int new_size = size + 1; 
	Product *tmp_product = new Product[new_size]; 
	//dua san vao menu  
	for ( int i = 0; i < size; i++)
	{ 
		tmp_product[i] = product[i];
	 } 
	// dau san pham moi vao vi tri cuoi cung 
	tmp_product[ new_size - 1 ] = new_product;  
	s 
	//xoa vung nhó cu  
	delete[] product; 
	product = tmp_product;
	size = new_size; 
	
	cout << "Them san pham thanh cong: "<<endl;  
		 
}



//ham xoa san pham 
void delete_product(Product* &product, int &size)
{
	// nhap ten muon xoa
    cout << "Nhap ten san pham can xoa: ";

	//khai nao ten san pham can xóa ss 
    string deleted_name;
    cin.ignore();
    getline(cin, deleted_name);
	
	// tim index cua san pham chung ta can xoa  
    int deleted_index = -1;//index chua du?c gan ne gia tr? khoi dau -1 
    for (int i = 0; i < size; i++)
    {//so sanh san pham nhap vao
	//xem có trung ten voi san pham trong danh sach khong  
	 
        if (!deleted_name.compare(product[i].name))
        {
            deleted_index = i;
            break;
        }//neu nhap sai ten thì se khong vao truong hop nay
		//nen xét them deleted_index == -1 
    }
		
    if (deleted_index == -1)
    {
        cout << "Khong tim thay san pham!" << endl;
        return;
    }
	//xoa san pham khoi mang  
    for (int i = deleted_index; i < size - 1; i++) 
    {
        product[i] = product[i + 1];
    }
    size--;
    
	//tao vung nho moi có so luong phan tu la sizz sau 
	// khi bi tru 1 don vi  
    Product *tmp_product = new Product[size];
	
	//copy vung nho cu sang vung nho moi  
    for(int i = 0; i < size; i++) 
    {
        tmp_product[i] = product[i];
    }

    delete[] product;
    product = tmp_product;

    cout << "Xoa thanh cong!" << endl;
}





 
 
 

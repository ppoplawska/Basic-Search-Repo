//Author: Patrick Poplawska
//UFID: 07169115
//DATE: 3/19/2015
//RE-UPLOAD DATE: 3/24/2015

#include<iostream> // used for IO
//#include<fstream> // used for file input, used during testing
#include<string> // used for compiler situations
#include<algorithm> // used for sort
//#include<ctime> // used to measure processing time, used during testing


class Search {

public:

	/*
		We have two searching algorithms binary, and linear search following
		specifications listed in Exercise 2

		In the main/interface we accept 3 separate commands.
		One to establish basic variables ( i.e array length, and number of search-able objects )
		The Second to list all values in our interval
		Third: The search-able values.

		For steps two and three we store these values in arrays for easy retrival and testing.

		*/

	bool linear_search(int e, int n, int* x){ //linear search method
		//e = target element, x is the elements array, n is the size of the array
		for (int i = 0; i < n; i++){
			if (x[i] == e){
				return true;
			}

		}
		return false;

	}

	bool binary_search(int e, int n, int* x){ // standard binary search, split down the middle and create sub intervals.
		//e = target element, x is the elements array, n is the size, 
		int bottom = 0;// index defining the bottom bound of the interval
		int top = n; //index defining the top bound of the interval
		int mid; //index defining the midpoint of the interval

		while (bottom <= top){
			mid = bottom + (top - bottom) / 2;
			if (x[mid] == e){ //target found
				return true;
			}
			else if (x[mid] < e){ //isolate to right interval (remove left side of midpoint)

				bottom = mid + 1;
			}
			else{ //isolate to left interval (remove right side of midpoint)
				top = mid - 1;
			}
		}
		return false;

	}
};



int main(){ //client interface as defined by exercise 2

	Search sch; // usable object
	int n; // total number of elements in the array
	int s; // number of elements that we are searching for.
	int* elements; //will contain the elements to be searched
	int* searchQuery; // will contain elements that we are looking for
	int target;//Target of search

	/* This is used for file reading and measuring time. (Not needed in final program)*/

	//clock_t clock1;//measures the processor clocks during program execution
	//std::ifstream myfile;
	//myfile.open("output.txt");

	//if (myfile.fail()){

	//	std::cout << "Failed to access input source ";
	//	exit(1);

	//}

	
	std::cin >> n >> s; //determining total number of elements and total number of searches
		

		elements = new int[n];
		searchQuery = new int[s];

		for(int i = 0; i < n; i++){ //loads all elements
			std::cin >> elements[i];
		}
		for(int i = 0; i < s; i++){ //loads all search queries
			std::cin >> searchQuery[i];
		}
		std::sort(elements, elements+n);
		std::cout<<"Linear Search"<<std::endl;
		 
		//clock1 = clock();
		for(int i = 0; i<s;i++){

			target = searchQuery[i];
			 
			if(sch.linear_search(target,n,elements)){ //searches begin
				std::cout<<"Yes"<<std::endl;
			}
			else{
				std::cout<<"No"<<std::endl;
			}
			
		}

		/*clock1 = clock() - clock1;
		float fclock1 = (float)clock1 / CLOCKS_PER_SEC;
		std::cout << "Processing time: " << fclock1 << " seconds"<< std::endl;*/
		
		
		std::cout<<"Binary Search"<<std::endl;
		
		//clock1 = clock();
		for(int i = 0; i<s;i++){

			target = searchQuery[i];
			
			if(sch.binary_search(target,n,elements )){
				std::cout<<"Yes"<<std::endl;
			}
			else{
				std::cout<<"No"<<std::endl;
			}
			
		}

		/*clock1 = clock() - clock1;
		fclock1 = (float)clock1 / CLOCKS_PER_SEC;
		std::cout << "Processing time: " << fclock1 << " seconds" << std::endl;*/
		
}

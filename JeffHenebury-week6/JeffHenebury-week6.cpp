// JeffHenebury-week6.cpp :
// 
// code per assignment 
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Publication {
private:
	struct Author {
		string firstName;
		string lastName;
	};
	vector<Author> Authors; //is there a way to specify max of 3?

protected:
	string publicationName;
	double publicationPrice;

public:

	void setPublicationPrice(double x) {
		publicationPrice = x;
	}

	double getPublicationPrice() {
		return publicationPrice;
	}

	void setAuthors(string firstN, string lastN) {
		Author author1;
		author1.firstName = firstN;
		author1.lastName = lastN;
		Authors.push_back(author1);
	};

	void setAuthors(string firstAuth_firstN, string firstAuth_lastN, string secondAuth_firstN, string secondAuth_lastN) {
		Author author1;
		Author author2;
		author1.firstName = firstAuth_firstN;
		author1.lastName = firstAuth_lastN;
		author2.firstName = secondAuth_firstN;
		author2.lastName = secondAuth_lastN;
		Authors.push_back(author1);
		Authors.push_back(author2);
	};

	void setAuthors(string firstAuth_firstN, string firstAuth_lastN, string secondAuth_firstN, string secondAuth_lastN, string thirdAuth_firstN, string thirdAuth_lastN) {
		Author author1;
		Author author2;
		Author author3;
		author1.firstName = firstAuth_firstN;
		author1.lastName = firstAuth_lastN;
		author2.firstName = secondAuth_firstN;
		author2.lastName = secondAuth_lastN;
		author3.firstName = thirdAuth_firstN;
		author3.lastName = thirdAuth_lastN;
		Authors.push_back(author1);
		Authors.push_back(author2);
		Authors.push_back(author3);
	};

	string listAuthors() {
		string authorList;
		for (int x = 0; x < Authors.size(); x++) {
			authorList = authorList + Authors[x].lastName + ", ";
			char firstName_firstLetter = Authors[x].firstName[0];
			authorList = authorList + firstName_firstLetter + "., ";
			//cout << "TEST:" << authorList;

		}
		return authorList;
	}
};

class Book : public Publication {
public:
	string isbn;
	int pages;
	int yearOfPub;
	// string title; dont need these, b/c they'll inherit?
	//int price;


	void setpublicationName(string x) {
		publicationName = x;
	};
	string getTitle() {
		return publicationName;
	};

	Book(int myPrice) {	//book constructor
		publicationPrice = myPrice;
		};
	};

	//create Journal
	class Journal : public Publication {
	public:
		string issn;		

		void setJournalName(string x) {
			publicationName = x;	//using publicationName from Publication
		};
		string getJournalName() {
			return publicationName;
		};
	};

	class Article : public Journal {
	public:
		int volumeNumber;
		int issueNumber;
		int yearOfPub;
		int firstPage;
		int lastPage;
		string articleTitle;

		//constructor:
		Article(double cost) {
			setPublicationPrice(cost);
		};

		string citation() {
			string citation;
			citation = listAuthors() + " (" + to_string(yearOfPub) + "). " + articleTitle + "."
				+ getJournalName() + ", " + to_string(volumeNumber) + " (" + to_string(issueNumber) + "), " 
				+ to_string(firstPage) + "-" + to_string(lastPage);
			return citation;
		};
	};

int main()
{
	Publication pub1;
	
	Book book1(12);	//using constructor to set price
	book1.setAuthors("Manuel", "Oliveira", "Julia", "Roberts");
	book1.isbn = 9876543210;
	book1.pages = 123;
	book1.yearOfPub = 1995;
	
	Article article1(60);	//set price in constructor
	article1.setJournalName(" International Journal of Computation");	//inherits from parent
	article1.setAuthors("Joan", "Rider");
	article1.articleTitle = "A novel C++ program";
	article1.yearOfPub = 1996;
	article1.volumeNumber = 4;
	article1.issueNumber = 2;
	article1.firstPage = 45;
	article1.lastPage = 49;
	
	Publication	works[20];	//create an array of Publication
	works[0] = pub1;
	
	 
	for (int x = 1; x < 20; x++) {	//not using  sizeof(works) for now
		Publication *myPointer = works; //create a pointer to the array
		if (x % 2 == 1) {	//for evens...
			works[x] = book1;
			//cout << "TEST: Current iteration is ODD: " << x << endl;
		}
		else  {		// ...and for odds
			works[x] = article1;
			//cout << "Current iteration is EVEN: " << (x) << endl;
		}
	}
	
	//testing, did the above loop work?
	//cout << "TEST of listAuthors 14: " << works[14].listAuthors() << endl;
	//cout << "TEST of listAuthors 15: " << works[15].listAuthors() << endl;

	cout << "**Printing just the prices**" << endl;
	for (int x = 0; x < 20; x ++) {	//loop through and print prices in the array
		cout <<"$" << works[x].getPublicationPrice()<<".00" << endl;

	}
	cout << "\n";
	cout << "**Printing the article citation**" << endl;
	cout << article1.citation() << endl;
	cout << "\n";


}

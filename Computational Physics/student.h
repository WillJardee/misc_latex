// structure to define a student

typedef struct{

	char* first_name;
	char* last_name;
	
	double grade;
	char letter_grade[3];
	
	char curved;

} Student_t;

int read_grades(char*, Student_t*);
void calculate_letter_grade(Student_t*, int, char[][11], double[], int);
void print_grades(char*, Student_t*, int);

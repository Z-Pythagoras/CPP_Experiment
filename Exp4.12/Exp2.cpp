#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

/*人员对象，存储姓名，性别，出生年月，ID号码*/
class Personel {
public:
	Personel();
	Personel(string, string, string, string);
	friend ostream& operator<<(ostream& out, Personel& x); //重载<<，输出姓名，性别，出生年月
protected:
	string name, sex, birth, idnum;
};

Personel::Personel() {
	name = sex = birth = idnum = "NULL";
}

Personel::Personel(string nm, string sx, string bt, string id) {
	name = nm;
	sex = sx;
	birth = bt;
	idnum = id;
}

ostream& operator<<(ostream& out, Personel& x) {
	out << x.name << " " << x.sex << " " << x.birth;
	return out;
}

/*课程对象，存储课程编号，课程名称，课程老师*/
class Subject {
public:
	Subject();
	Subject(string, string, string);
	friend ostream& operator<<(ostream& out, Subject& x);
	string Getid(); //定义获得课程编号接口
	string Getteacher(); //定义获得课程老师接口
private:
	string subid, subname, subteacher;
};

Subject::Subject() {
	subid = subname = subteacher = "NULL";
}

Subject::Subject(string id, string nm, string tch) {
	subid = id;
	subname = nm;
	subteacher = tch;
}

ostream& operator<<(ostream& out, Subject& x) {
	cout << x.subid << " " << x.subname << " " << x.subteacher;
	return out;
}

string Subject::Getid() {
	return subid;
}

string Subject::Getteacher() {
	return subteacher;
}

/*成绩对象，存储学生ID号码，课程编号，课程成绩*/
class Grade {
public:
	Grade();
	Grade(string, string, string);
	friend ostream& operator<<(ostream& out, Grade& x);
	string Getgrade(); //定义获得课程成绩接口
private:
	string stuid, subid, subgrade;
};

Grade::Grade() {
	stuid = subid = subgrade = "NULL";
}

Grade::Grade(string id1, string id2, string gd) {
	stuid = id1;
	subid = id2;
	subgrade = gd;
}

ostream& operator<<(ostream& out, Grade& x) {
	cout << x.subgrade;
	return out;
}

string Grade::Getgrade() {
	return subgrade;
}

/*人员数据库对象，存储人员对象，并定义插入修改接口，查找接口，删除接口*/
class Personeldatabase {
public:
	void Insert(string, Personel);
	Personel Find(string);
	void Delete(string);
private:
	map<string, Personel> DB; //使用map存储人员对象，并以ID号码作为索引
};

void Personeldatabase::Insert(string id, Personel inf) {
	DB[id] = inf;
}

Personel Personeldatabase::Find(string id) {
	map<string, Personel>::iterator it = DB.find(id);
	Personel ans;
	if (it != DB.end())
		ans = it->second;
	return ans;
}

void Personeldatabase::Delete(string id) {
	if (DB.find(id) != DB.end())
		DB.erase(DB.find(id));
}

Personeldatabase StudentDatabase;
Personeldatabase TeacherDatabase;

/*课程数据库对象，存储课程对象，并定义插入修改接口，查找接口，删除接口*/
class Subjectdatabase {
public:
	void Insert(string, Subject);
	Subject Find(string);
	void Delete(string);
private:
	map<string, Subject> DB; //使用map存储课程对象，并以课程名称作为索引
};

void Subjectdatabase::Insert(string nm, Subject sbj) {
	DB[nm] = sbj;
}

Subject Subjectdatabase::Find(string nm) {
	map<string, Subject>::iterator it = DB.find(nm);
	Subject ans;
	if (it != DB.end())
		ans = it->second;
	return ans;
}

void Subjectdatabase::Delete(string nm) {
	if (DB.find(nm) != DB.end())
		DB.erase(DB.find(nm));
}

Subjectdatabase SubjectDatabase;

/*成绩数据库对象，存储成绩对象，并定义插入修改接口，查找接口，删除接口*/
class Gradedatabase {
public:
	friend void Insert(string, string, Grade, Gradedatabase&);
	void Insert(string, string, Grade);
	Grade Find(string, string);
	void Delete(string, string);
private:
	map<string, Grade> DB; //使用map存储成绩对象，并以学生ID号码拼接课程ID号码作为索引
};

void Gradedatabase::Insert(string stuid, string subid, Grade sbj) {
	DB[stuid + subid] = sbj;
}

void Insert(string stuid, string subid, Grade sbj, Gradedatabase& x) {
	x.DB[stuid + subid] = sbj;
}

Grade Gradedatabase::Find(string stuid, string subnm) {
	string subid = SubjectDatabase.Find(subnm).Getid();
	map<string, Grade>::iterator it = DB.find(stuid + subid);
	Grade ans;
	if (it != DB.end())
		ans = it->second;
	return ans;
}

void Gradedatabase::Delete(string stuid, string subid) {
	if (DB.find(stuid + subid) != DB.end())
		DB.erase(DB.find(stuid + subid));
}

Gradedatabase GradeDatabase;

/*学生对象，继承人员对象，并定义查找老师接口，查询成绩接口*/
class Student : public Personel {
public:
	Student();
	Student(string, string, string, string);
	string Findteacher(string);
	string Getgrade(string);
};

Student::Student() {
	name = sex = birth = idnum = "NULL";
}

Student::Student(string nm, string sx, string bt, string id) {
	name = nm;
	sex = sx;
	birth = bt;
	idnum = id;
}

string Student::Findteacher(string sub) {
	Subject x = SubjectDatabase.Find(sub);
	return x.Getteacher();
}

string Student::Getgrade(string sub) {
	Grade x = GradeDatabase.Find(idnum, sub);
	return x.Getgrade();
}

/*老师对象，继承人员对象，并定义查找学生接口，修改成绩接口*/
class Teacher : public Personel {
public:
	Teacher();
	Teacher(string, string, string, string);
	Personel Getstudent(string);
	void Setgrade(string, string, Grade, Gradedatabase&);
};

Teacher::Teacher() {
	name = sex = birth = idnum = "NULL";
}

Teacher::Teacher(string nm, string sx, string bt, string id) {
	name = nm;
	sex = sx;
	birth = bt;
	idnum = id;
}

Personel Teacher::Getstudent(string id) {
	return StudentDatabase.Find(id);
}

void Teacher::Setgrade(string stuid, string subid, Grade sbj, Gradedatabase& gde) {
	Insert(stuid, subid, sbj, gde);
}

int main() {
	/*初始化数据库*/
	Personel stu1("李逵", "男", "1963.8", "20120801");
	Personel stu2("花千羽", "女", "1999.10", "20131011");
	Personel stu3("TF - BOY", "男", "2003.9", "20140901");
	Personel stu4("冷冰冰", "女", "2010.12", "20151217");
	StudentDatabase.Insert("20120801", stu1);
	StudentDatabase.Insert("20131011", stu2);
	StudentDatabase.Insert("20140901", stu3);
	StudentDatabase.Insert("20151217", stu4);

	Personel tch1("孙悟空", "男", "1950.8", "t20011211");
	Personel tch2("张三丰", "男", "1979.10", "t20160708");
	TeacherDatabase.Insert("t20011211", tch1);
	TeacherDatabase.Insert("t20160708", tch2);

	Subject sub1("COM002", "知识图谱", "孙悟空");
	Subject sub2("COM016", "大数据", "张三丰");
	SubjectDatabase.Insert("知识图谱", sub1);
	SubjectDatabase.Insert("大数据", sub2);

	Grade grd1("20120801", "COM002", "86");
	Grade grd2("20131011", "COM002", "77");
	Grade grd3("20140901", "COM002", "90");
	Grade grd4("20151217", "COM002", "59");
	GradeDatabase.Insert("20120801", "COM002", grd1);
	GradeDatabase.Insert("20131011", "COM002", grd2);
	GradeDatabase.Insert("20140901", "COM002", grd3);
	GradeDatabase.Insert("20151217", "COM002", grd4);
	/*初始化数据库完成*/

	Student stuu("冷冰冰", "女", "2010.12", "20151217");
	cout << stuu.Findteacher("知识图谱") << endl; //学生查找老师
	cout << stuu.Getgrade("知识图谱") << endl; //学生查询成绩

	Teacher tchh("孙悟空", "男", "1950.8", "t20011211");
	Personel st111 = tchh.Getstudent("20151217"); //老师查找学生
	cout << st111 << endl;
	Grade grd4_1("20151217", "COM002", "66");
	tchh.Setgrade("20151217", "COM002", grd4_1, GradeDatabase); //老师添加或修改成绩
	cout << stuu.Getgrade("知识图谱") << endl;

	return 0;
}

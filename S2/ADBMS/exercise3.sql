-- 01 
CREATE DATABASE University;
USE University;

CREATE TABLE Student (
	name VARCHAR(50),
    student_number INT PRIMARY KEY,
    class INT,
    major VARCHAR(50)
);

CREATE TABLE Course (
	course_name VARCHAR(50),
    course_number VARCHAR(50) PRIMARY KEY,
    credit_hours INT,
    department VARCHAR(50)
);

CREATE TABLE Section (
	section_identifier INT PRIMARY KEY,
    course_number VARCHAR(50),
    semester VARCHAR(50),
    year YEAR,
    instructor VARCHAR(50),
    FOREIGN KEY (course_number) REFERENCES Course(course_number)
);

CREATE TABLE Grade_report (
	student_number INT,
    section_identifier INT,
    grade VARCHAR(10),
    PRIMARY KEY (student_number, section_identifier),
    FOREIGN KEY (student_number) REFERENCES Student(student_number),
    FOREIGN KEY (section_identifier) REFERENCES Section(section_identifier)
);

CREATE TABLE Prerequisite (
	course_number VARCHAR(50),
    prerequisite_number VARCHAR(50),
    PRIMARY KEY (course_number, prerequisite_number),
    FOREIGN KEY (course_number) REFERENCES Course(course_number),
    FOREIGN KEY (prerequisite_number) REFERENCES Course(course_number)
);

-- 02
INSERT INTO Student VALUES ("Smith",17,1,"CS");
INSERT INTO Student VALUES ("Brown",8,2,"CS");

INSERT INTO Course VALUES ("Intro To Computer Science","CS1310",4,"CS");
INSERT INTO Course VALUES ("Data Structures","CS3320",4,"CS");
INSERT INTO Course VALUES ("Discrete Mathematics","MATH2410",3,"MATH");
INSERT INTO Course VALUES ("Database","CS3380",3,"CS");

INSERT INTO Section VALUES (85,"MATH2410","Fall",07,"King");
INSERT INTO Section VALUES (92,"CS1310","Fall",07,"Anderson");
INSERT INTO Section VALUES (102,"CS3320","Spring",08,"Knuth");
INSERT INTO Section VALUES (112,"MATH2410","Fall",08,"Chang");
INSERT INTO Section VALUES (119,"CS1310","Fall",08,"Anderson");
INSERT INTO Section VALUES (135,"CS3380","Fall",08,"Stone");

INSERT INTO Grade_report VALUES (17,112,"B");
INSERT INTO Grade_report VALUES (17,119,"C");
INSERT INTO Grade_report VALUES (8,85,"A");
INSERT INTO Grade_report VALUES (8,92,"A");
INSERT INTO Grade_report VALUES (8,102,"B");
INSERT INTO Grade_report VALUES (8,135,"A");

INSERT INTO Prerequisite VALUES ("CS3380","CS3320");
INSERT INTO Prerequisite VALUES ("CS3380","MATH2410");
INSERT INTO Prerequisite VALUES ("CS3320","CS1310");

-- 03
SELECT Student.name, Course.course_name, Grade_report.grade FROM Grade_report
INNER JOIN Student ON Student.student_number=Grade_report.student_number
INNER JOIN Section ON Section.section_identifier=Grade_report.section_identifier
INNER JOIN Course ON Course.course_number=Section.course_number
WHERE Student.name="Smith";

-- 04
SELECT name, grade FROM Student
INNER JOIN Grade_report ON Grade_report.student_number=Student.student_number
INNER JOIN Section ON Section.section_identifier=Grade_report.section_identifier
INNER JOIN Course ON Course.course_number=Section.course_number
WHERE Course.course_name="Database" AND Section.year=08;

-- 05
SELECT course_name FROM Course
JOIN Prerequisite ON Course.course_number = Prerequisite.prerequisite_number
WHERE Prerequisite.course_number = (
	SELECT course_number FROM Course 
	WHERE course_name = 'Database'
);
-- SELECT c2.course_name FROM Course c1
-- JOIN Prerequisite p ON c1.course_number = p.course_number
-- JOIN Course c2 ON p.prerequisite_number = c2.course_number
-- WHERE c1.course_name = 'Database';

-- 06
CREATE VIEW seniors AS
SELECT name FROM Student
WHERE major="CS" AND class="2";
SELECT * FROM seniors;

-- 07
SELECT course_name FROM Course
JOIN Section ON Section.course_number = Course.course_number
WHERE instructor="King" AND YEAR BETWEEN 07 AND 08;

-- 08
SELECT Section.course_number, Section.semester, Section.year, COUNT(Student.name) FROM Section
JOIN Course on Course.course_number = Section.course_number
JOIN Student ON Student.major = Course.department
WHERE Section.instructor="King"
GROUP BY Section.course_number, Section.semester, Section.year;

-- 09
SELECT Student.name, Course.course_name, Course.course_number, Course.credit_hours, Section.semester, Section.year, Grade_report.grade
FROM Student
JOIN Grade_report ON Grade_report.student_number = Student.student_number
JOIN Section ON Section.section_identifier = Grade_report.section_identifier
JOIN Course ON Course.course_number = Section.course_number
WHERE Student.class = "4" AND Student.major = "CS";

-- 10
INSERT INTO Student VALUES ("Johnson", 25, 1, "Math");
UPDATE Student SET class = 2 WHERE name = "Smith";
INSERT INTO Course VALUES ("Knowledge Engineering", "CS4390", 3, "CS");
DELETE FROM Student WHERE name = "Smith" AND student_number = 17;


-- Contents
SELECT * FROM Student;
SELECT * FROM Course;
SELECT * FROM Section;
SELECT * FROM Grade_report;
SELECT * FROM Prerequisite;

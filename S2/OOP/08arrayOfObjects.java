class Student {
    int id;
    String name;

    Student(int id, String name) {
        this.id = id;
        this.name = name;
    }

    void display() {
        System.out.println(id + " " + name);
    }
}

class Main {
    public static void main(String[] args) {
        Student[] students = new Student[3];

        students[0] = new Student(1, "Alice");
        students[1] = new Student(2, "Bob");
        students[2] = new Student(3, "Charlie");

        for (int i = 0; i < students.length; i++) {
            students[i].display();
        }
    }
}
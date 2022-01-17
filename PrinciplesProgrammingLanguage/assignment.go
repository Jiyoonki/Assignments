package main

import (
	"fmt"
	"time"
)

type Teacher struct {
	name string
	age int
	teaches string
}


type Student struct {
	name string
	age int
	ID_no int
}

type Visiting struct {
	name string
	age int
	ID_no int
	valid_thru time.Time
}

func (s Teacher) PrintDetails() {
	fmt.Println("Name:", s.name, "Age:", s.age, "Teaches:", s.teaches)
}

func (s Student) PrintDetails() {
	fmt.Println("Name:", s.name, "Age:", s.age, "ID_no:", s.ID_no)
}

func (s Visiting) PrintDetails() {
	fmt.Println("Name:", s.name, "Age:", s.age, "Valid_thru", s.valid_thru)
}

func main() {
	fmt.Print("A few CAU members...", "\n")

	var harry = Teacher{name:"Harry", age:time.Now().AddDate(-1971, -12, -7).Year(), teaches:"Programming Languages"}
	var natasha = Teacher{name:"Natasha", age:time.Now().AddDate(-1975, -9, -21).Year(), teaches:"Forbidden Archeology"}
	var yk = Student{name:"YK", age:time.Now().AddDate(-1999, -3, -16).Year(), ID_no:2051}
	var sh = Student{name:"SH", age:time.Now().AddDate(-2000, -10, -5).Year(), ID_no:4968}
	var alice = Visiting{name:"Alice", age:time.Now().AddDate(-1995, -7, -14).Year(), ID_no:9595, valid_thru: time.Date(int(2019), time.September, int(25), int(0), int(0), int(0), int(0), time.UTC)}
	var vanessa = Visiting{name:"Vanessa", age:time.Now().AddDate(-1998, -3, -27).Year(), ID_no:9598,valid_thru: time.Date(2019, time.February, int(28), int(0), int(0), int(0), int(0), time.UTC)}
	
	harry.PrintDetails()
	natasha.PrintDetails()
	yk.PrintDetails()
	sh.PrintDetails()
	alice.PrintDetails()
	vanessa.PrintDetails()
}

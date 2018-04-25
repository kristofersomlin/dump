#!/usr/bin/python3
print("Hello, World!")
student_names = ["Mark", "Katarina", "Jessica"]
print(student_names)
student_names.append('Homer')
student_names.append('Kristofer')
#del studets_names[2]
print(student_names)

x = 0
for index in range(10): # index blir räknaren på loopen
   x += 10
   print("The value of X is {0}".format(x))
x = 0
for index in range(5,10,2): # börjar på 5, slutar på 10, ökar med 2 varje gång.
   x += 10
   print("The value of X is {0}".format(x))

for name in student_names:
    if name == "Kristofer":
        print("Found him! " + name)
        break
    print("Currently testing " + name)

student = {
    "name": "Mark",
    "student_id": 15163,
    "feedback": None
    }
all_students = [
    {"name": "Mark", "student_id": 15163 },
    {"name": "Katarina", "student_id": 63112 },
    {"name": "Jessica", "student_id": 30021 }
    ]
print(student.keys())


student["last_name"] = "Kowalski"


try:
    last_name = student["last_name"]
    numbered_last_name = 3 + last_name
except KeyError:
    print("error finding last_name")
except TypeError as error:
    print("i cant add theese two together!!")
    print(error)
except Exception:
    print("Uknown error?!?")
print("will execute this aswell!")


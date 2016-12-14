import os,sys
from subprocess import call

CONTENT_PRE = """
LD = g++
CC = g++
EXEC = PType
all : $(EXEC)

"""

#CONFIG du compilateur
GCC = "g++"

#ARGUMENTS
arg = sys.argv
list_only=[]
list_remove=[]
for i in range(1,len(arg)):
	if(arg[i]=="-r"):
		for j in range(i+1,len(arg)):
			list_remove.append(arg[j])
		break
	else:
		list_only.append(arg[i])

list_dir = os.listdir("./")
list_cpp=[]
list_o = []
for nom in list_dir:
	if(".cpp" in nom):
		list_cpp.append(nom)


#ONLY SELECTION
list_cpp_p=[]
if(list_only!=[]):
	for sh in list_cpp:
		if(sh in list_only):
			list_cpp_p.append(sh)
	list_cpp=list_cpp_p[:]


#REMOVE
if(list_remove!=[]):
	for sh in list_remove:
		list_cpp.remove(sh)

for i in range(0,len(list_cpp)):
	charac = ""
	for c in list_cpp[i]:
		if(c=="."):
			break
		else:
			charac+=c
	list_o.append(charac+".o")



CONTENT = "PType : "

#Finale .o compile
for name in list_o:
	CONTENT+= name + " "

CONTENT+="\n"
CONTENT+="\t"+GCC+" "

for name in list_o:
	CONTENT+=name+" "

CONTENT+= "-o Ptype-app -lsfml-graphics -lsfml-window -lsfml-system \n"

CONTENT+="\n"

#Compile .cpp
list_o.remove("main.o")
#Main
name="main.o"
CONTENT+=name+": "+name[:-2]+".cpp"
for oname in list_o:
	CONTENT+= " "+oname[:-2]+".hpp"
	
CONTENT+="\n"
CONTENT+="\t"+GCC+" -c "+name[:-2]+".cpp" + " -o " + name+"\n"
CONTENT+="\n"


for name in list_o:	
	CONTENT+=name+": "+name[:-2]+".cpp" +" "+ name[:-2]+".hpp"+"\n"
	CONTENT+="\t"+GCC+" -c "+name[:-2]+".cpp" + " -o " + name+"\n"
	CONTENT+="\n"



CONTENT_POST = """

clean : 
	rm -rf *.o
	
cleanAll :
	rm -rf *.o
	rm -rf $(EXEC)
"""



f = open("Makefile","w")
f.write(CONTENT_PRE+CONTENT+CONTENT_POST)
f.close()
	

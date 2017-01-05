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


#GET FILES
list_dir = os.listdir("./")

#get subdirs
list_subdir = []
for di in list_dir:
	if os.path.isdir(di) and di[0]!='.':
		list_subdir.append(di)
		
for di in list_subdir:
	list_dir.remove(di)

list_subdir.append("./")

list_cpp=[]
list_o = []

for di in list_subdir:
	list_get_files = os.listdir(di)
	
	for nom in list_get_files:
		if(".cpp" in nom):
			if(di!="./"):
				list_cpp.append(di+"/"+nom)
			else:
				list_cpp.append(nom)



#ONLY SELECTION
list_cpp_p=[]
if(list_only!=[]):
	for sh in list_cpp:
		for ssh in list_only:
			if(ssh in sh):
				list_cpp_p.append(sh)
	list_cpp=list_cpp_p[:]


#REMOVE
if(list_remove!=[]):
	for sh in list_remove:
		for rm in list_cpp:
			if(sh in rm):
				list_cpp.remove(rm)
				break

#generate .o files
for i in range(0,len(list_cpp)):
	charac = ""
	for c in list_cpp[i]:
		if(c=="."):
			break
		else:
			charac+=c
	list_o.append(charac+".o")


for fileDisp in list_o:
	print(fileDisp)

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
for rm in list_o:
	if("main.o" in rm):
		list_o.remove(rm)
		break
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



#build remove
REMOVE = ""

for subdir in list_subdir:
	if(subdir!="./"):
		REMOVE+= "\t rm ./" + subdir + "/*.o \n"
	else:
		REMOVE += "\t rm *.o \n"


CONTENT_POST = """

clean : 
"""
CONTENT_POST+= REMOVE
CONTENT_POST+= """

cleanAll :
"""
CONTENT_POST+= REMOVE
CONTENT_POST+="""
	rm -rf $(Ptype-app)
"""



f = open("Makefile","w")
f.write(CONTENT_PRE+CONTENT+CONTENT_POST)
f.close()
	

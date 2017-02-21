##########################################
#
##  Exemple de Makefile
#  Eric Lecolinet - Reda Dehak - Telecom ParisTech 2015
#  #  INF224 - TP Java/Swing - http://www.telecom-paristech.fr/~elc/inf224
#
###########################################

## Nom du programme (doit correspondre au fichier qui contient main())
PROG = Main
## Fichiers sources .java
SOURCES = RemoteControl.java Main.java
## Compilateur Java
#
JC = javac
## Options du compilateur Java
JFLAGS = -g

all: classes

run: all
	java ${PROG}

classes: $(SOURCES:.java=.class)

clean:
	-@$(RM) *.class 1>/dev/null 2>&1
	
tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java

CPP = g++
TARGET = Practica2EDD

# all
all: .all-post

.all-post: ArbolAVL.o Campo.o Contacto.o Graficar.o ListaCampos.o nombreCampos.o TablaHashCampo.o TablaHashGrupo.o Util.o  main.o
	$(CPP) ArbolAVL.o Campo.o Contacto.o Graficar.o ListaCampos.o nombreCampos.o TablaHashCampo.o TablaHashGrupo.o Util.o  main.o -o $(TARGET)


ArbolAVL.o: ArbolAVL.cpp ArbolAVL.h
	$(CPP) -c ArbolAVL.cpp

Campo.o: Campo.cpp Campo.h
	$(CPP) -c Campo.cpp

Contacto.o: Contacto.cpp Contacto.h
	$(CPP) -c Contacto.cpp

Graficar.o: Graficar.cpp Graficar.h
	$(CPP) -c Graficar.cpp

ListaCampos.o: ListaCampos.cpp ListaCampos.h
	$(CPP) -c ListaCampos.cpp

nombreCampos.o: nombreCampos.cpp nombreCampos.h
	$(CPP) -c nombreCampos.cpp

TablahashCampos.o: TablahashCampos.cpp TablahashCampos.h
	$(CPP) -c TablahashCampos.cpp


TablaHashGrupo.o: TablaHashGrupo.cpp TablaHashGrupo.h
	$(CPP) -c TablaHashGrupo.cpp


Util.o: Util.cpp Util.h
	$(CPP) -c Util.cpp




main.o:
	$(CPP) -c main.cpp


# clean
clean:
	rm -f *.o $(TARGET)
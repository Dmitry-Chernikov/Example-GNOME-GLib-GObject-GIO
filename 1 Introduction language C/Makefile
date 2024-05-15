sysdir=/usr
libdir=$(sysdir)/local/lib
incdir=$(sysdir)/local/include

#gcc main.c -o app3 $(pkg-config --cflags --libs polykotes)

app: main.o polysqr.o kotes.o
	@echo "Сборка $@"
	@gcc $^ -o $@

applib: install
	@echo "Сборка из lib $@"
	@gcc main.c -o applib -I$(incdir)/polykotes -L$(libdir) -lpolykotes


main.o: main.c
	@echo "Компилирую $^"
	@gcc -c $^

polysqr.o: polysqr.c
	@echo "Компилирую $^"
	@gcc -c $^

kotes.o: kotes.c
	@echo "Компилирую $^"
	@gcc -c $^

clean:
	@rm -f app* *.o *.a *.pc

install: polykotes.pc libpolykotes.a
	@echo "Установка библиотеки"
	@rm -rf $(incdir)/polykotes
	@mkdir $(incdir)/polykotes
	@echo "Копируем заголовочные файлы polysqr.h и kotes.h"
	@cp polysqr.h kotes.h $(incdir)/polykotes
	@echo "Копируем библиотеку libpolykotes.a"
	@rm -rf $(libdir)/libpolykotes.a
	@cp libpolykotes.a $(libdir)
	@mv polykotes.pc $(libdir)/pkgconfig/polykotes.pc

libpolykotes.a: polysqr.o kotes.o
	@echo "Создание $@"
	@ar rcs $@ $^

polykotes.pc:
	@echo "Name: Testtest" > polykotes.pc
	@echo "Description: My first lib" >> polykotes.pc
	@echo "Version: 0.0.1" >> polykotes.pc
	@echo "Cflags: -I$(incdir)/polykotes" >> polykotes.pc
	@echo "Libs: -L$(libdir) -lpolykotes" >> polykotes.pc

run:
	@./app


gcc main.c -o app3 $(pkg-config --cflags --libs polykotes)

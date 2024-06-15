# Makefile для проекта lab4

# Опции компилятора
CXX = g++
CXXFLAGS = -std=c++17

# Директории
SRC_DIR = .
INC_DIR = data heap node util linkedlist test uiengine uiengine/controller uiengine/util

# Файлы
SRCS = $(wildcard $(addsuffix /*.cpp, $(SRC_DIR)) $(addsuffix /*.cpp, $(INC_DIR)))
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

# Имя исполняемого файла
EXEC = lab4

# Цель по умолчанию
all: $(EXEC)

# Правило для компиляции .cpp файлов в .o файлы
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Правило для связывания .o файлов в исполняемый файл
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Цель для очистки (удаления временных файлов)
clean:
	rm -f $(OBJS) $(DEPS) $(EXEC)

# Включение файлов зависимостей
-include $(DEPS)

%.o: %.cpp
	g++ $(CXX_OPTS) -c $< -o $@

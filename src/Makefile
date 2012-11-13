all:
	cppcms_tmpl_cc interface.tmpl -o interface.cpp
	g++ -shared -fPIC interface.cpp -o libinterface.so -lcppcms -lbooster
	g++ -rdynamic main.cpp Network.cpp Neuron.cpp Layer.cpp Interface.cpp -o main -lcppcms -lbooster

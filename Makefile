#
#
include Rule.in

#set -e

INCDIR =  -I./

TARGET=dockerclient

LIBS += -lpthread -ldl -lm  -lz -lm -lssl -lcrypto -lidn -lrt

##TLV OBJECT
OBJS =  restclient/connection.o restclient/callbacks.o restclient/restclient.o \
        json/jsoncpp.o container_client.o docker_client.o network_client.o volume_client.o service_client.o


%.o: %.c
	$(CC) $(INCDIR) $(CFLAGS)  -fPIC  -c $<  -o $@ 

%.o: %.cc
	$(CXX) $(INCDIR) $(CXXFLAGS)   -fPIC  -c $<  -o $@ 
	
%.o: %.cpp
	$(CXX) $(INCDIR) $(CXXFLAGS)   -fPIC  -c $<  -o $@ 

SHARED_LIB = libdockerclient.so

$(TARGET): main.o $(SHARED_LIB)
	$(CXX) main.o $(LDFLAGS) -ldockerclient $(LIBS)   -o $(TARGET) 
	
$(SHARED_LIB):$(OBJS)
	$(CXX) $(OBJS)  -fPIC -shared -o $(SHARED_LIB)
	
 
#	$(CP) $(TARGET)  $(INSTALL_DIR)

clean:
	$(RM) -f $(OBJS)
	$(RM) -f $(TARGET)
	$(RM) -f *.cgi *.o *.d
	








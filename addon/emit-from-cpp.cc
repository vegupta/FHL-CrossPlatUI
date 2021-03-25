#include <napi.h>
#include "threat.h"
#include <chrono>
#include <iostream>
#include <thread>

Napi::Object getNapiThreatObject(Threat t, Napi::Env env) {
Napi::Object obj = Napi::Object::New(env);
  obj.Set("name", t.name);
  obj.Set("type", t.type);
  obj.Set("path", t.path);
  return obj;
}


Napi::Value CallEmit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Function emit = info[0].As<Napi::Function>();
  emit.Call({Napi::String::New(env, "start")});
  //int array[5] = {1,2,3,4,5};
  Threat t1("EICAR","VIRUS","c://Desktop/eicar");
  Threat t2("OpenFileTest","Behavior", "/var/run/python2.4");
  Threat t3("Cripto.rpm","Adware", "/home/user/Adware");
  Threat t4("abc.zip","ARCHIVE BOMB", "/tmp/abc.zip");
  Threat t5("Potential Unwanted App","PUA", "bin/pua");

  // Send array of objects
  Threat threats[5];
  threats[0] = t1;
  threats[1] = t2;
  threats[2] = t3;
  threats[3] = t4;
  threats[4] = t5;

  Napi::Array outputArray = Napi::Array::New(env, 5);
  for(int k = 0; k < 5; k++) {
  	outputArray[k] = getNapiThreatObject(threats[k], env);
  }
 emit.Call({Napi::String::New(env, "data"), outputArray}); 
  

  return Napi::String::New(env, "OK");
}

// Init
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "callEmit"),
              Napi::Function::New(env, CallEmit));
  return exports;
}

NODE_API_MODULE(emit_from_cpp, Init);




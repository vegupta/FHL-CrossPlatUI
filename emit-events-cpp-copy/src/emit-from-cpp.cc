#include <napi.h>
#include "threat.h"
#include <chrono>
#include <iostream>
#include <thread>

Napi::Object getNapiThreatObject(Threat t, Napi::Env env) {
Napi::Object obj = Napi::Object::New(env);
  obj.Set("name", t.name);
  obj.Set("type", t.type);
  obj.Set("status", t.status);
  return obj;
}


Napi::Value CallEmit(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Function emit = info[0].As<Napi::Function>();
  emit.Call({Napi::String::New(env, "start")});
  //int array[5] = {1,2,3,4,5};
  Threat t1("EICAR","VIRUS", "Removed");
  Threat t2("OpenFileTest","Behavior", "Quarantined");
  
  for (int i = 0; i < 3; i++) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
      //Napi::Array outputArray = Napi::Array::New(env, 5);
  /*for (int j = 0; j < 5; j++) {
    outputArray[j] = Napi::Number::New(env, int(array[j]));
  }
    emit.Call(
        {Napi::String::New(env, "data"), outputArray});
  }*/
  
  
  // Send array of objects
  Threat threats[2];
  threats[0] = t1;
  threats[1] = t2;
  Napi::Array outputArray = Napi::Array::New(env, 2);
  for(int k = 0; k < 2; k++) {
  	outputArray[k] = getNapiThreatObject(threats[k], env);
  }
 emit.Call(
        {Napi::String::New(env, "data"), outputArray}); 
  }
  emit.Call({Napi::String::New(env, "end")}); 

  return Napi::String::New(env, "OK");
}

// Init
Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "callEmit"),
              Napi::Function::New(env, CallEmit));
  return exports;
}

NODE_API_MODULE(emit_from_cpp, Init);




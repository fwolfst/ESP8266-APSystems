#ifndef AAA_INVERTERS_H
#define AAA_INVERTERS_H

#include <pgmspace.h>

const char INV_SCRIPT[] PROGMEM = R"=====(
function showFunction() {
  //alert("showFunction");
  document.getElementById("invspan").style.display = "inline";
}
function hideFunction() {
  //alert("showFunction");
  document.getElementById("invspan").style.display = "none";
}
function myFunction(){
 if(document.getElementById("sel").value == 1 ) { 
    showFunction();
 } else {
   hideFunction();
 }
}

function delFunction(a) {
  if(confirm("are you sure to delete this inverter ?")) {  
  document.getElementById("bo").innerHTML="<br>wait...<br>processing<br>your<br>request"; 
  document.getElementById("bo").style.display="block";
  document.getElementById('formular').submit();   
  setTimeout(function(){window.location.href=a;}, 3000 ); 
  }
}

)====="; 


#endif
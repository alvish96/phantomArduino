
/*
   SD.open(filepath)
  SD.open(filepath, mode)

  filename: the name the file to open, which can include directories (delimited
  by forward slashes, /) - char *

  mode (optional): the mode in which to open the file, defaults to FILE_READ - byte.
  one of:

  FILE_READ: open the file for reading, starting at the beginning of the file.
  FILE_WRITE: open the file for reading and writing, starting at the end of the file.

  a File object referring to the opened file; if the file couldn't be opened,
  this object will evaluate to false in a boolean context,
  i.e. you can test the return value with "if (f)".
*/

void save()
{
  Serial.print(rtc.getTimeStr());
  Serial.print(",");
  Serial.println(int(rtc.getTemp()));

  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile)
  {
    myFile.print(rtc.getTimeStr());
    myFile.print(",");
    myFile.println(int(rtc.getTemp()));
    myFile.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }
}

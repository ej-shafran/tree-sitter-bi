:b bi 56
This is BI, a very simple format for data transference.

:b bi 495
What you are currently reading is a blob field!

BI only has two field kinds, "blob" and "int".
Blob fields can contain any arbitrary bytes, such as text.
Int fields contain integers.

You write a field by denoting its type (as either ":i " or ":b "), then its name.
For blob fields, there then comes the length of the blob's content, a newline, and the blob itself.
For int fields, it's just the integer value itself.
Finally, we add a newline at the end.

For example, see this integer field:

:i number 123
:b text 174
That field has a name of "number", and a value of 123.

Notice that names don't have to be unique within the file;
the first two fields in this file both have the name "bi"!

:b Anything but newlines is allowed in names, including spaces! 43
This value isn't anything special, though.

:b We can even have numbers! Look: 123 456 789 256
Notice, however, that only the final number on the previous line is highlighted, because it is the length of the blob and not part of the name.

This means the name of this field is "We can even have numbers! Look: 123 456 789", whereas its length is 256.

:i This even works for integer fields - 111 222
:b nesting 266
Of course, since blobs are just any arbitrary data, you can include more BI inside of them.
This next field, for example, is actually still a part of this blob, because it is included in the length denoted in the "nesting" field.

:b nested 22
This field is nested!

:b not-nested 80
This field is no longer nested! We're out of the length of the "nesting" field.

:b Get Creative! 912
The useful thing about BI is just how easy it is to implement within any coding language.

In fact, here's the entire Python code for parsing and writing BI, **within a BI file**!

```
def read_blob_field(f, name):
  line = f.readline()
  field = b':b ' + name + b' '
  assert line.startswith(field), field
  assert line.endswith(b'\n')
  size = int(line[len(field):-1])
  blob = f.read(size)
  assert f.read(1) == b'\n'
  return blob

def read_int_field(f, name):
  line = f.readline()
  field = b':i ' + name + b' '
  assert line.startswith(field), field
  assert line.endswith(b'\n')
  return int(line[len(field):-1])

def write_int_field(f, name, value):
  f.write(b':i %s %d\n', (name, value))

def write_blob_field(f, name, value):
  f.write(b':b %s %d\n' % (name, len(value)))
  f.write(blob)
  f.write(b'\n')
```

(Source code courtesy of [rere.py](https://github.com/tsoding/rere.py/blob/main/rere.py))


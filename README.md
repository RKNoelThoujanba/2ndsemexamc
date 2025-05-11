<h2> Dependencies </h2> <br>

Compiler that supports C17 and C++17 <br>
cmake 3.30 minimum <br>
python3<br>
Build System supported by cmake<br>
For example, A relatively modern Visual Studio installation like VS 2019 or later, GNU Make, MinGW Make, Ninja etc<br>


<br> <br> <br>
<h2> Build: </h2> <br>
mkdir build <br>
cd build <br>
cmake .. <br>
cmake --build . --config &lt;Debug/Release/RelWithDebInfo&gt; -j &lt;threads to be spawned&gt; <br>
 <br>
<br> <hr> <br>
<br>

<h2> Runner: </h2> <br>
You can also run Runner.py to run the executables after building with cmake <br>
python3 Runner.py &lt;exec name&gt;<br>
<br> OR <br>
python3 Runner.py
<br> <br>
this will prompt you for the executable name <br>

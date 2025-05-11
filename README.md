<h2> Dependencies </h2> <br>
<ol>

    <li>Compiler that supports C17 and C++17</li>
    <li>cmake 3.30 minimum</li>
    <li>python3</li>

</ol>

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

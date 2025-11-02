<?php
echo "
    <table border = '2px' cellspacing = '1px' cellpadding = '10x'>
    <tr><th colspan='2'>PROGRESS REPORT</th></tr>
    <tr><td>NAME </td><td>".$_POST["name"]."</td></tr>
    <tr><td>AGE </td><td>".$_POST["age"]."</td></tr>
    <tr><td>MARK 1 </td><td>".$_POST["mark-1"]."</td></tr>
    <tr><td>MARK 2</td><td>".$_POST["mark-2"]."</td></tr>
    <tr><td>MARK 3 </td><td>".$_POST["mark-3"]."</td></tr>
    <tr><td>TOTAL MARK </td><td>".$_POST["totalMark"]."</td></tr>
    </table>";
  <?php
    if(isset($_POST['click']))
    {
        $filename = "serverstream.txt";
        file_put_contents($filename, "1");
	}
    ?>
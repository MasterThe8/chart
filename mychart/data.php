        <?php
        $file = fopen("id.txt", "r") or die("Unable to open file!");
        while (!feof($file)) {
            $line = fgets($file);
            echo $line;
        }
        fclose($file);
        ?>
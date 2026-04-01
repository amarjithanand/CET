CREATE DEFINER=`root`@`localhost` PROCEDURE `parity`(IN x INT)
BEGIN
    IF x % 2 = 0
    THEN SELECT "even";
    ELSE SELECT "odd";
    END IF;
END

CREATE DEFINER=`root`@`localhost` PROCEDURE `grade`(IN mark INT)
BEGIN
	DECLARE grade VARCHAR(3);
    IF mark > 89
    THEN SET grade = "A";
    ELSEIF mark > 79
    THEN SET grade = "B";
    ELSEIF mark > 69
    THEN SET grade = "C";
    ELSEIF mark > 59
    THEN SET grade = "D";
    ELSE SET grade = "E";  
    END IF;
    SELECT grade;
END

CREATE DEFINER=`root`@`localhost` PROCEDURE `factorial`(IN n INT)
BEGIN
	DECLARE fact INT DEFAULT 1;
	WHILE n > 0
    DO
		SET fact = fact * n;
        SET n = n - 1;
	END WHILE;
    SELECT fact;
END

CREATE DEFINER=`root`@`localhost` PROCEDURE `day`(IN yyyymmdd DATE)
BEGIN
	SELECT dayname(yyyymmdd);
END

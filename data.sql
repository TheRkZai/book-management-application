-- MySQL dump 10.13  Distrib 5.5.19, for Win64 (x86)
--
-- Host: localhost    Database: booksalesmanagement
-- ------------------------------------------------------
-- Server version	5.5.19-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `bookrefund`
--

DROP TABLE IF EXISTS `bookrefund`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bookrefund` (
  `sno` int(8) NOT NULL AUTO_INCREMENT,
  `refundtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `ISBN` char(13) NOT NULL,
  `bookname` varchar(300) NOT NULL,
  `author` varchar(200) DEFAULT NULL,
  `bookconcern` varchar(200) DEFAULT NULL,
  `price` float NOT NULL,
  `refundcount` int(4) NOT NULL,
  PRIMARY KEY (`sno`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bookrefund`
--

LOCK TABLES `bookrefund` WRITE;
/*!40000 ALTER TABLE `bookrefund` DISABLE KEYS */;
/*!40000 ALTER TABLE `bookrefund` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger update_after_refund after insert on bookrefund
for each row
begin
    update bookstorage set storecount=storecount+new.refundcount where ISBN=new.ISBN;
    update bookreport set soldcount=soldcount-new.refundcount where ISBN=new.ISBN;
    update bookreport set soldsum=soldcount*price;
end */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `bookreport`
--

DROP TABLE IF EXISTS `bookreport`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bookreport` (
  `ISBN` char(13) NOT NULL,
  `bookname` varchar(300) NOT NULL,
  `author` varchar(200) DEFAULT NULL,
  `bookconcern` varchar(200) DEFAULT NULL,
  `price` float NOT NULL,
  `soldcount` int(4) NOT NULL,
  `soldsum` float NOT NULL,
  PRIMARY KEY (`ISBN`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bookreport`
--

LOCK TABLES `bookreport` WRITE;
/*!40000 ALTER TABLE `bookreport` DISABLE KEYS */;
/*!40000 ALTER TABLE `bookreport` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `booksold`
--

DROP TABLE IF EXISTS `booksold`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `booksold` (
  `sno` int(8) NOT NULL AUTO_INCREMENT,
  `soldtime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `ISBN` char(13) NOT NULL,
  `bookname` varchar(300) NOT NULL,
  `author` varchar(200) DEFAULT NULL,
  `bookconcern` varchar(200) DEFAULT NULL,
  `price` float NOT NULL,
  `soldcount` int(4) NOT NULL,
  PRIMARY KEY (`sno`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `booksold`
--

LOCK TABLES `booksold` WRITE;
/*!40000 ALTER TABLE `booksold` DISABLE KEYS */;
/*!40000 ALTER TABLE `booksold` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger insert_after_vend after insert on booksold
for each row
begin
     update bookstorage set storecount=storecount-new.soldcount where ISBN=new.ISBN;
     if((select count(*) from bookreport where bookreport.ISBN = new.ISBN) <> 0) then 
         update bookreport set soldcount=soldcount+new.soldcount,soldsum=soldcount*price where ISBN=new.ISBN;
     else 
         insert into bookreport values(new.ISBN, new.bookname, new.author, new.bookconcern, new.price,new.soldcount,new.price*new.soldcount);
     end if;
end */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `bookstock`
--

DROP TABLE IF EXISTS `bookstock`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bookstock` (
  `sno` int(8) NOT NULL AUTO_INCREMENT,
  `stocktime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `ISBN` char(13) NOT NULL,
  `bookname` varchar(300) DEFAULT NULL,
  `author` varchar(200) DEFAULT NULL,
  `bookconcern` varchar(200) DEFAULT NULL,
  `cost` float NOT NULL,
  `stockcount` int(4) NOT NULL,
  PRIMARY KEY (`sno`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bookstock`
--

LOCK TABLES `bookstock` WRITE;
/*!40000 ALTER TABLE `bookstock` DISABLE KEYS */;
/*!40000 ALTER TABLE `bookstock` ENABLE KEYS */;
UNLOCK TABLES;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 trigger insert_after_stock after insert on bookstock
for each row
begin
     if((select count(*) from bookstorage where bookstorage.ISBN = new.ISBN) <> 0) then 
         update bookstorage set storecount=storecount+new.stockcount,cost=new.cost where ISBN=new.ISBN;
     else 
         insert into bookstorage values(new.ISBN, new.bookname, new.author, new.bookconcern, new.cost*1.12,new.stockcount,new.cost);
     end if;
end */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `bookstorage`
--

DROP TABLE IF EXISTS `bookstorage`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bookstorage` (
  `ISBN` char(13) NOT NULL,
  `bookname` varchar(300) NOT NULL,
  `author` varchar(200) DEFAULT NULL,
  `bookconcern` varchar(200) DEFAULT NULL,
  `price` float NOT NULL,
  `storecount` int(4) NOT NULL,
  `cost` float NOT NULL,
  PRIMARY KEY (`ISBN`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bookstorage`
--

LOCK TABLES `bookstorage` WRITE;
/*!40000 ALTER TABLE `bookstorage` DISABLE KEYS */;
/*!40000 ALTER TABLE `bookstorage` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `supplier`
--

DROP TABLE IF EXISTS `supplier`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `supplier` (
  `sno` int(8) NOT NULL AUTO_INCREMENT,
  `supplytime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `ISBN` char(13) NOT NULL,
  `bookname` varchar(300) NOT NULL,
  `author` varchar(200) DEFAULT NULL,
  `supplier` varchar(300) NOT NULL,
  `supplycost` float NOT NULL,
  `supplycount` int(4) NOT NULL,
  PRIMARY KEY (`sno`,`supplytime`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `supplier`
--

LOCK TABLES `supplier` WRITE;
/*!40000 ALTER TABLE `supplier` DISABLE KEYS */;
/*!40000 ALTER TABLE `supplier` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `usertable`
--

DROP TABLE IF EXISTS `usertable`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `usertable` (
  `username` varchar(100) NOT NULL,
  `password` varchar(100) DEFAULT NULL,
  `rank` enum('职工','供货商','管理员') DEFAULT NULL,
  PRIMARY KEY (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `usertable`
--

LOCK TABLES `usertable` WRITE;
/*!40000 ALTER TABLE `usertable` DISABLE KEYS */;
INSERT INTO `usertable` VALUES ('root','1234','管理员');
/*!40000 ALTER TABLE `usertable` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'booksalesmanagement'
--
/*!50003 DROP PROCEDURE IF EXISTS `insert_into_refund` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8 */ ;
/*!50003 SET character_set_results = utf8 */ ;
/*!50003 SET collation_connection  = utf8_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'STRICT_TRANS_TABLES,NO_AUTO_CREATE_USER,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50020 DEFINER=`root`@`localhost`*/ /*!50003 PROCEDURE `insert_into_refund`(refundtime timestamp,ISBN char(13),bookname varchar(50),author	varchar(20), bookconcern	varchar(20),price	float(8),refundcount int(4))
Begin
       if(refundcount <= (select bookreport.soldcount	 from bookreport where bookreport.ISBN=ISBN)) then
          insert into bookrefund (refundtime, ISBN, bookname, author, bookconcern, price, refundcount) values(refundtime,ISBN,bookname,author,bookconcern,price,refundcount);
       end if;
End */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2016-01-05 20:33:01

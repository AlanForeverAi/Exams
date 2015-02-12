-- MySQL dump 10.13  Distrib 5.6.17, for Win32 (x86)
--
-- Host: localhost    Database: qtdb
-- ------------------------------------------------------
-- Server version	5.6.22-log

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
-- Table structure for table `manager`
--

DROP TABLE IF EXISTS `manager`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `manager` (
  `teacherid` int(11) NOT NULL,
  `name` varchar(45) DEFAULT NULL,
  `password` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`teacherid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `manager`
--

LOCK TABLES `manager` WRITE;
/*!40000 ALTER TABLE `manager` DISABLE KEYS */;
INSERT INTO `manager` VALUES (12345,'浚','12345');
/*!40000 ALTER TABLE `manager` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `obanswers`
--

DROP TABLE IF EXISTS `obanswers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `obanswers` (
  `fpaperid` int(11) NOT NULL DEFAULT '0',
  `studentid` varchar(11) NOT NULL DEFAULT '',
  `answers` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`fpaperid`,`studentid`),
  KEY `ob-uers` (`studentid`),
  KEY `fpaper` (`fpaperid`),
  CONSTRAINT `FK_obanswers_papermark` FOREIGN KEY (`fpaperid`, `studentid`) REFERENCES `papermark` (`fpaperid`, `fuserid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `obanswers`
--

LOCK TABLES `obanswers` WRITE;
/*!40000 ALTER TABLE `obanswers` DISABLE KEYS */;
INSERT INTO `obanswers` VALUES (5,'20112100004','A-,D-,D-,A-,D-,'),(6,'20112100004','B-,B-,B-,B-,B-,');
/*!40000 ALTER TABLE `obanswers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `obquestions`
--

DROP TABLE IF EXISTS `obquestions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `obquestions` (
  `obid` int(11) NOT NULL AUTO_INCREMENT,
  `title` mediumtext,
  `answer` varchar(4) DEFAULT NULL,
  `type` int(11) DEFAULT NULL,
  PRIMARY KEY (`obid`)
) ENGINE=InnoDB AUTO_INCREMENT=126 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `obquestions`
--

LOCK TABLES `obquestions` WRITE;
/*!40000 ALTER TABLE `obquestions` DISABLE KEYS */;
INSERT INTO `obquestions` VALUES (114,'“对内整顿朝政，对外‘尊王攘夷’。终于成就了春秋之首的伟业。”材料中这位历史人物是（  ）@a齐桓公@b晋文公@c宋襄公@d楚庄王','A-',2),(115,'比较评价历史人物，是历史学科能力要求之一。华盛顿、拿破仑作为资产阶级政治家，其历史作用的相同之处是（  ） @a赢得了民族独立@b维护了国家统一 @c打击了封建势力@d推动了资产阶级民主政治进程 ','D-',2),(116,'英国资产阶级革命、美国独立战争、法国大革命的共同点是（  ）@a确立了三权分立的原则@b确立了资产阶级的君主立宪制@c建立了资产阶级共和国@d改变了原来社会的性质','D-',2),(117,'有人说他是疯子，也有人说他是英雄，但谁也无法否认他对欧洲所产生的巨大影响，他因战争起家，也因战争而倒台，更因一部法典而名扬欧洲。这位名震一时的枭雄是（  ）@a拿破仑       @b 查理一世@c华盛顿@d亚历山大','A-',2),(118,'1931年，一位科学家病重将要离世的消息牵动着世界人民的心，几十名记者为他守夜，每隔一个小时就对外发布一次消息：“灯”还亮着。这位科学家是（  ）@a瓦特@b法拉第  @c爱迪生@d爱因斯坦','C-',2),(119,'莎士比亚在作品中赞叹道：“人是一件多么了不起的杰作！在理性上多么高贵！在才能上多么无限！”如果列夫·托尔斯泰这位杰出人物的成就来证明的话，下列哪一选项符合@a出版了《物种起源》@b撰写了《战争与和平》@c创作了《向日葵》@d谱写了《英雄交响曲》','A-',2),(120,'美苏争霸的两极解体的标志是（   ） @a东欧剧变、苏联解体@b“一 超多强”局面的暂时形成@c世界政治格局多极化趋势的发展@d第三世界国家的奋起','A-',2),(121,'2011年8月12日，第（）  届世界大学生夏季运动会在中国  （）开幕。本届大运会的口号为“从这里开始”，中国代表队最终夺75金创造新纪录。@a23   香港 @b24  合肥@c25  广州 @d26  深圳','D-',3),(122,'2011年11月3日和11月14日，     和     成功实现了两次交会对接，而掌握空间交会对接技术是我国载人航天又一次历史性的突破和重大的技术跨越。   @a天宫一号   神州六号 @b嫦娥一号   神州六号  @c天宫一号  神州八号 @d嫦娥二号  神州八号','C-',3),(123,'雷锋曾说“不经风雨，长不成大树；不受百炼，难以成钢。”启示我们要     （    ）@a自尊自信  @b自立自强@c互助互爱@d无私奉献','B-',3),(124,'美国商界有句名言：“如果你不能战胜对手，就加入到他们中间去。”现代竞争，不再是“你死我活”，而是更高层次的竞争与合作，现代企业追求的不再是“单赢”而是“双赢”和“多赢”。 说明 @a当今世界只有合作，不存在竞争@b互相竞争才能成就伟大事业@c合作是新形势下实现共同发展的必由之路   @d合作比竞争更重要','C-',3),(125,'甘肃庆阳校车事故发生后，安徽省省长王三运就做好学校交通安全工作作出重要指示。要求公安、教育等部门立即开展全省中小学幼儿园交通安全专项检查，查找薄弱环节，提出整改要求，建立长效机制，切实较强学校及周边道路交通安全管理，全面做好中小学校和幼儿园交通安全各项工作。这体现对未成年人的哪方面保护         @a社会保护  @b学校保护   @c司法保护@d家庭保护','A-',3);
/*!40000 ALTER TABLE `obquestions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `paper`
--

DROP TABLE IF EXISTS `paper`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `paper` (
  `paperid` int(11) NOT NULL AUTO_INCREMENT,
  `obquids` varchar(100) DEFAULT NULL,
  `subquids` varchar(100) DEFAULT NULL,
  `totalmark` int(11) DEFAULT NULL,
  `percent` int(11) DEFAULT NULL,
  `description` varchar(100) DEFAULT NULL,
  `time` int(11) DEFAULT NULL,
  `subject` int(11) DEFAULT NULL,
  PRIMARY KEY (`paperid`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `paper`
--

LOCK TABLES `paper` WRITE;
/*!40000 ALTER TABLE `paper` DISABLE KEYS */;
INSERT INTO `paper` VALUES (5,'114,115,116,117,119,','23,24,25,26,27,',100,30,'alan',600,2),(6,'114,115,116,117,118,','23,24,',100,50,'a1',600,2),(7,'121,122,123,124,','29,30,31,33,',100,40,'alan',600,3);
/*!40000 ALTER TABLE `paper` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `papermark`
--

DROP TABLE IF EXISTS `papermark`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `papermark` (
  `obqumark` varchar(100) DEFAULT NULL,
  `subqumark` varchar(100) DEFAULT NULL,
  `totalmark` int(11) DEFAULT NULL,
  `fpaperid` int(11) NOT NULL,
  `fuserid` varchar(11) NOT NULL,
  `done` varchar(10) DEFAULT NULL,
  `finish` varchar(10) DEFAULT NULL,
  `date` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`fpaperid`,`fuserid`),
  KEY `user` (`fuserid`),
  KEY `fpaperid` (`fpaperid`),
  CONSTRAINT `FK_papermark_paper` FOREIGN KEY (`fpaperid`) REFERENCES `paper` (`paperid`),
  CONSTRAINT `FK_papermark_user` FOREIGN KEY (`fuserid`) REFERENCES `student` (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `papermark`
--

LOCK TABLES `papermark` WRITE;
/*!40000 ALTER TABLE `papermark` DISABLE KEYS */;
INSERT INTO `papermark` VALUES ('6,6,6,6,0,','7,7,7,7,7,',59,5,'20112100004','已完成','已批改','周二 二月 3 2015'),('0,0,0,0,0,',NULL,0,6,'20112100004','已完成','未批改','周六 一月 24 2015');
/*!40000 ALTER TABLE `papermark` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `serveridtype`
--

DROP TABLE IF EXISTS `serveridtype`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `serveridtype` (
  `id` int(11) NOT NULL,
  `type` varchar(45) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `serveridtype`
--

LOCK TABLES `serveridtype` WRITE;
/*!40000 ALTER TABLE `serveridtype` DISABLE KEYS */;
INSERT INTO `serveridtype` VALUES (1,'管理员'),(2,'历史'),(3,'政治');
/*!40000 ALTER TABLE `serveridtype` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `serveruser`
--

DROP TABLE IF EXISTS `serveruser`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `serveruser` (
  `userid` int(11) NOT NULL,
  `name` varchar(45) NOT NULL,
  `password` varchar(45) NOT NULL,
  `type` int(11) NOT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `serveruser`
--

LOCK TABLES `serveruser` WRITE;
/*!40000 ALTER TABLE `serveruser` DISABLE KEYS */;
INSERT INTO `serveruser` VALUES (111,'lan','111',2),(123,'lan','123',3),(1234,'lan','1234',3);
/*!40000 ALTER TABLE `serveruser` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `student`
--

DROP TABLE IF EXISTS `student`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `student` (
  `userid` varchar(20) NOT NULL,
  `name` varchar(45) DEFAULT NULL,
  `grade` int(11) DEFAULT NULL,
  `class` int(11) DEFAULT NULL,
  `password` varchar(45) DEFAULT NULL,
  PRIMARY KEY (`userid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `student`
--

LOCK TABLES `student` WRITE;
/*!40000 ALTER TABLE `student` DISABLE KEYS */;
INSERT INTO `student` VALUES ('123456','123456',1,1,'123456'),('20102100001','小小',1,1,'123'),('20102100002','张晓东',1,1,'123'),('20102100003','王小明',1,1,'123'),('20102100004','李刚',1,1,'123'),('20102100005','郑维明',1,1,'123'),('20102100006','孙大宝',1,1,'123'),('20102100007','罗伟',1,1,'123'),('20112100001','lan',1,1,'123'),('20112100004','alan',1,1,'123');
/*!40000 ALTER TABLE `student` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `subanswers`
--

DROP TABLE IF EXISTS `subanswers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `subanswers` (
  `fpaperid` int(11) NOT NULL DEFAULT '0',
  `studentid` varchar(11) NOT NULL DEFAULT '',
  `answer1` longtext,
  `answer2` longtext,
  `answer3` longtext,
  `answer4` longtext,
  `answer5` longtext,
  `answer6` longtext,
  `answer7` longtext,
  `answer8` longtext,
  `answer9` longtext,
  `answer10` longtext,
  `answer11` longtext,
  `answer12` longtext,
  `answer13` longtext,
  `answer14` longtext,
  `answer15` longtext,
  `answer16` longtext,
  `answer17` longtext,
  `answer18` longtext,
  `answer19` longtext,
  `answer20` longtext,
  PRIMARY KEY (`fpaperid`,`studentid`),
  KEY `sub-paper` (`fpaperid`),
  KEY `sub-user` (`studentid`),
  CONSTRAINT `FK_subanswers_papermark` FOREIGN KEY (`fpaperid`, `studentid`) REFERENCES `papermark` (`fpaperid`, `fuserid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `subanswers`
--

LOCK TABLES `subanswers` WRITE;
/*!40000 ALTER TABLE `subanswers` DISABLE KEYS */;
INSERT INTO `subanswers` VALUES (5,'20112100004','12\n','12','12','12','12',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(6,'20112100004','123','123',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);
/*!40000 ALTER TABLE `subanswers` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `subquestions`
--

DROP TABLE IF EXISTS `subquestions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `subquestions` (
  `subid` int(11) NOT NULL AUTO_INCREMENT,
  `title` mediumtext,
  `type` int(11) DEFAULT NULL,
  PRIMARY KEY (`subid`)
) ENGINE=InnoDB AUTO_INCREMENT=34 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `subquestions`
--

LOCK TABLES `subquestions` WRITE;
/*!40000 ALTER TABLE `subquestions` DISABLE KEYS */;
INSERT INTO `subquestions` VALUES (23,'日本在近代史上发动了哪两次侵华战争？请你举出日本侵略者屠杀中国人民所制造的个惨案。',2),(24,'在经济领域开启中国近代化的事件是什么？',2),(25,'中国近代民族工业发展的黄金时期是在哪一时期？请列举出得以发展的内因和外因。',2),(26,'20世纪50年代末，在中国探索建设社会主义道路中，出现了违背客观经济规律、超越社会发展阶段的哪两大运动？该错误得到彻底纠正是在哪次会议上？20世纪80年代我国农村改革的主要内容是什么？',2),(27,'1929年资本主义世界爆发了经济大危机，美国是如何应对的？面对当前金融危机的影响，当年美国的做法中最值得我们借鉴的地方是？',2),(28,'当今世界经济格局发展呈何趋势？请举出中国积极顺应该趋势的最重大活动。',2),(29,'如何把握生产力与生产关系的矛盾运动和演变规律？',3),(30,'为什么说私人劳动与社会劳动的矛盾是简单商品生产的基本矛盾？',3),(31,'为什么说商品是使用价值和价值的矛盾统一体？',3),(33,'马克思主义政治经济学的研究对象有什么特点？',3);
/*!40000 ALTER TABLE `subquestions` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2015-02-09 18:56:50

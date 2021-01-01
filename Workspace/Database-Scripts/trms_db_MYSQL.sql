-- Database Name: trms_db
-- Database Name Abbreviation Long Form: Task Reminder Management System (TRMS) Database (DB)

-- Accessing trms_db database
USE trms_db


-- Creating Table 1 - AccountStatus
CREATE TABLE AccountStatus(
  AccountStatusID INT NOT NULL AUTO_INCREMENT,
  AccountStatus VARCHAR(8) NOT NULL,
  PRIMARY KEY (AccountStatusID)
)ENGINE=INNODB;

-- Inserting records into Table 1 - AccountStatus
INSERT INTO AccountStatus(AccountStatus)
VALUES 
("Active"),
("Disabled");


-- Creating Table 2 - Login
CREATE TABLE Login(
  LoginID INT NOT NULL AUTO_INCREMENT,
  EmailAddress VARCHAR(100) UNIQUE,
  PasswordHash VARCHAR(150),
  asAccountStatusID INT NOT NULL, 
  PRIMARY KEY (LoginID),
  FOREIGN KEY (asAccountStatusID) REFERENCES AccountStatus(AccountStatusID)
)ENGINE=INNODB;

-- Inserting records into Table 2 - Login
INSERT INTO Login(EmailAddress, PasswordHash, asAccountStatusID)
Values ("mchatte@toplist.cz", "8944854914295023676", 1); -- Password: ChattEddie3$


-- Creating Table 3 - AccountType
CREATE TABLE AccountType(
	AccountTypeID INT NOT NULL AUTO_INCREMENT,
    AccountType VARCHAR(19) NOT NULL,
    PRIMARY KEY (AccountTypeID)
)ENGINE=INNODB;

-- Inserting records into Table 3 - AccountType
INSERT INTO AccountType(AccountType)
VALUES
("StandardUserAccount"),
("PremiumUserAccount"),
("AdminAccount");


-- Creating Table 4 - BooleanValue
CREATE TABLE BooleanValue(
	BooleanValueID INT NOT NULL AUTO_INCREMENT,
    BooleanValue BOOLEAN NOT NULL,
    PRIMARY KEY (BooleanValueID)
)ENGINE=INNODB;

-- Inserting records into Table 4 - BooleanValue
INSERT INTO BooleanValue(BooleanValue)
VALUES
(true),
(false);


-- Creating Table 5 - Account
CREATE TABLE Account(
	AccountID INT NOT NULL AUTO_INCREMENT,
    FirstName VARCHAR(40) NOT NULL,
    MiddleName VARCHAR(40),
    LastName VARCHAR(50) NOT NULL,
    CreatedDateTime DATETIME NOT NULL,
    atAccountTypeID INT NOT NULL,
    dvDoNotDistrubBooleanValueID INT NOT NULL,
    lLoginID INT NOT NULL,
    PRIMARY KEY (AccountID),
    FOREIGN KEY (atAccountTypeID) REFERENCES AccountType(AccountTypeID),
    FOREIGN KEY (dvDoNotDistrubBooleanValueID) REFERENCES BooleanValue(BooleanValueID),
    FOREIGN KEY (lLoginID) REFERENCES Login(LoginID)
)ENGINE=INNODB;

-- Inserting records into Table 5 - Account
INSERT INTO Account(FirstName, MiddleName, LastName, CreatedDateTime, atAccountTypeID, dvDoNotDistrubBooleanValueID, lLoginID)
VALUES
("Eddie", "Mellicent", "Chatt", "2020-12-28 12:55:28", 1, 2, 1);


-- Creating Table 6 - AccountActivity 
CREATE TABLE AccountActivity(
	AccountActivityID INT NOT NULL AUTO_INCREMENT,
    AccountActivity VARCHAR(7) NOT NULL,
    PRIMARY KEY (AccountActivityID)
)ENGINE=INNODB;

-- Inserting records into Table 6 - AccountActivity
INSERT INTO AccountActivity(AccountActivity)
VALUES
("Online"),
("Offline");


-- Creating Table 7 - LoginActivity
CREATE TABLE LoginActivity(
	LoginActivityID INT NOT NULL AUTO_INCREMENT,
    LoginDateTime DATETIME NOT NULL,
    LogoutDateTime DATETIME NOT NULL,
    OperatingSystemSpec VARCHAR(50) NOT NULL,
    aaAccountActivityID INT NOT NULL,
    lLoginID INT NOT NULL,
    PRIMARY KEY (LoginActivityID),
    FOREIGN KEY (lLoginID) REFERENCES Login(LoginID)
)ENGINE=INNODB;

-- Inserting records into Table 7 - LoginActivity
INSERT INTO LoginActivity(LoginDateTime, LogoutDateTime, OperatingSystemSpec, aaAccountActivityID, lLoginID)
VALUES
("2020-12-28 12:55:28", "2020-12-28 13:55:28", "-", 2, 1);


-- Creating Table 8 - ForgotPassword
CREATE TABLE ForgotPassword(
	RecoveryID INT NOT NULL AUTO_INCREMENT,
    PinCode VARCHAR(6) NOT NULL,
    NoOfTimesUsed INT NOT NULL,
    CreatedDateTime DATETIME NOT NULL,
    lLoginID INT NOT NULL,
    PRIMARY KEY(RecoveryID),
    FOREIGN KEY (lLoginID) REFERENCES Login(LoginID)
)ENGINE=INNODB;

-- Inserting records into Table 8 - ForgotPassword
INSERT INTO ForgotPassword(PinCode, NoOfTimesUsed, CreatedDateTime, lLoginID)
VALUES
("526871", 1, "2020-12-28 19:55:28", 1);


-- Creating Table 9 - CategoryColour
CREATE TABLE CategoryColour(
	ColourID INT NOT NULL AUTO_INCREMENT,
    HexColourCode VARCHAR(7) NOT NULL,
    PRIMARY KEY (ColourID)
)ENGINE=INNODB;

-- Inserting records into Table 9 - CategoryColour
INSERT INTO CategoryColour(HexColourCode)
VALUES
("#0C99E4");


-- Creating Table 10 - Category
CREATE TABLE Category(
	CategoryID INT NOT NULL AUTO_INCREMENT,
    CategoryName VARCHAR(50) NOT NULL,
    ccColourID INT NOT NULL,
    tPinnedTaskID INT,
    PRIMARY KEY (CategoryID)
)ENGINE=INNODB;

-- Inserting records into Table 10 - Category
INSERT INTO Category(CategoryName, ccColourID)
VALUES
("Work", 1);


-- Creating Table 11 - Task
CREATE TABLE Task(
	TaskID INT NOT NULL AUTO_INCREMENT,
    Title VARCHAR(50) NOT NULL,
    TaskDescription VARCHAR(100) NOT NULL,
    StartDateTime DATETIME NOT NULL,
    EndDateTime DATETIME NOT NULL,
    CreatedDateTime DATETIME NOT NULL,
    TerminationDateTime DATETIME,
    LastEditDateTime DATETIME NOT NULL,
    bvImportantBooleanValueID INT NOT NULL,
    aAccountID INT NOT NULL,
    cCategoryID INT NOT NULL,
    PRIMARY KEY (TaskID),
    FOREIGN KEY (bvImportantBooleanValueID) REFERENCES BooleanValue(BooleanValueID),
    FOREIGN KEY (aAccountID) REFERENCES Account(AccountID),
    FOREIGN KEY (cCategoryID) REFERENCES Category(CategoryID)
)ENGINE=INNODB;

-- Inserting records into Table 11 - Task
INSERT INTO Task(Title, TaskDescription, StartDateTime, EndDateTime, CreatedDateTime, LastEditDateTime, bvImportantBooleanValueID, aAccountID, cCategoryID)
VALUES
("Prepare Document", "Research on Big Analysis and prepare an analysis report", "2020-12-26 09:55:28", "2020-12-26 16:55:28", "2020-12-25 08:55:28", "2020-12-25 08:55:28",  1, 1, 1),
("Analyze Data", "Data analysis of collected data", "2020-12-28 10:55:28", "2020-12-28 12:55:28", "2020-12-27 08:55:28", "2020-12-27 08:55:28", 2, 1, 1);


-- MODIFICATION TO EXISTING TABLE: Altering Table 10 - Category to add foerign key
ALTER TABLE Category 
ADD FOREIGN KEY (tPinnedTaskID) REFERENCES Task(TaskID);

-- MODIFICATION TO EXISTING TABLE: Updating the records after altering Table 10 - Category with a new foreign key
UPDATE Category
SET tPinnedTaskID = 1
WHERE CategoryID = 1;


-- Creating Table 12 - SnoozeDuration
CREATE TABLE SnoozeDuration(
	SnoozeDurationID INT NOT NULL AUTO_INCREMENT,
    SnoozeDuration VARCHAR(2) NOT NULL,
    PRIMARY KEY(SnoozeDurationID)
)ENGINE=INNODB;

-- Inserting into Table 12 - SnoozeDuration
INSERT INTO SnoozeDuration(SnoozeDuration)
VALUES
("1"),
("5"),
("10"),
("15"),
("20"),
("30");


-- Create Table 13 - NoOfSnoozes
CREATE TABLE NoOfSnoozes(
	NoOfSnoozesID INT NOT NULL AUTO_INCREMENT,
    NoOfSnoozes VARCHAR(2) NOT NULL,
    PRIMARY KEY(NoOfSnoozesID)
)ENGINE=INNODB;

-- Inserting into Table 13 - NoOfSnoozes
INSERT INTO NoOfSnoozes(NoOfSnoozes)
VALUES
("1"),
("3"),
("5"),
("10");


-- Creating Table 14 - RepeatOccasion
CREATE TABLE RepeatOccasion(
	RepeatOccasionID INT NOT NULL AUTO_INCREMENT,
    RepeatOccasion VARCHAR(15) NOT NULL,
    PRIMARY KEY (RepeatOccasionID)
)ENGINE=INNODB;

-- Inserting into Table 14 - RepeatOccasion
INSERT INTO RepeatOccasion(RepeatOccasion)
VALUES
("Does not repeat"),
("Daily"),
("Weekly"),
("Monthly"),
("Yearly");


-- Creating Table 15 - Reminder
CREATE TABLE Reminder(
	ReminderID INT NOT NULL AUTO_INCREMENT,
    ReminderDateTime DATETIME NOT NULL,
    sdSnoozeDurationID INT,
    nosNoOfSnoozesID INT,
    rdRepeatOccasionID INT,
    tTaskID INT NOT NULL,
    PRIMARY KEY (ReminderID),
    FOREIGN KEY (sdSnoozeDurationID) REFERENCES SnoozeDuration(SnoozeDurationID),
    FOREIGN KEY (nosNoOfSnoozesID) REFERENCES NoOfSnoozes(NoOfSnoozesID),
    FOREIGN KEY (rdRepeatOccasionID) REFERENCES RepeatOccasion(RepeatOccasionID),
    FOREIGN KEY (tTaskID) REFERENCES Task(TaskID)
)ENGINE=INNODB;

-- Inserting records into Table 15 - Reminder
INSERT INTO Reminder(ReminderDateTime, tTaskID)
VALUES
("2020-12-26 08:55:28", 1);
INSERT INTO Reminder(ReminderDateTime, sdSnoozeDurationID, nosNoOfSnoozesID, rdRepeatOccasionID, tTaskID)
VALUES
("2020-12-28 09:55:28", 2, 2, 1, 2);


-- Creating Table 16 - Report
CREATE TABLE Report(
	ReportID INT NOT NULL AUTO_INCREMENT,
    ReportSubject VARCHAR(50) NOT NULL,
    Feedback VARCHAR(150) NOT NULL,
    SubmittedDateTime DATETIME NOT NULL,
    aAccountID INT NOT NULL,
    PRIMARY KEY (ReportID),
    FOREIGN KEY (aAccountID) REFERENCES Account(AccountID)
)ENGINE=INNODB;

-- Inserting records into Table 16 - Report
INSERT INTO Report(ReportSubject, Feedback, SubmittedDateTime, aAccountID)
VALUES
("Application is Working Well", "This task reminder application is working incredibly well.", "2020-12-27 05:55:28", 1);








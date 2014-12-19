create table serveruser (
	userid int(11) primary key,
	name varchar(45) not null,
	password varchar(45) not null,
	type int(11) not null
);

create table serveridtype (
    id int(11) primary key,
    type varchar(45) not null
);




Ball_Room_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Ball_Room_EventScript_BallDefault
	.byte 0


Ball_Room_EventScript_BallDefault::
	removeobject 6
	setvar STARTER_REGION, 0
	call Common_EventScript_SetupRivalGfxId
	return


Start_StarterChoose_Sequence::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, MeetBirch
	waitmovement 0
	msgbox BeginAdventureText
	waitmessage
	closemessage
	setvar LITTLEROOT_STATE, 1
	release
	return


Start_StarterChoose_Sequence_Left::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, MeetBirch2
	waitmovement 0
	goto Start_StarterChoose_Sequence
	return


MeetBirch:
	walk_up
	walk_up
	step_end

MeetBirch2:
	walk_right
	step_end

StopLeaving::
	lockall
	msgbox StopLeaving_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, DoNotLeave
	waitmovement 0
	releaseall
	return


DoNotLeave:
	walk_up
	step_end

Ball_Room_EventScript_Birch::
	goto_if_unset FLAG_SYS_POKEMON_GET, Ball_Room_EventScript_Birch_2
	msgbox Ball_Room_EventScript_Birch_Text_2, MSGBOX_NPC
Ball_Room_EventScript_Birch_1:
	end

Ball_Room_EventScript_Birch_2:
	lock
	faceplayer
	message Ball_Room_EventScript_Birch_Text_0
	delay 240
	closemessage
	multichoice 25, 1, MULTI_STARTER_CHOICE, 0
	compare VAR_RESULT, 0
	goto_if_eq Ball_Room_EventScript_Birch_6
	compare VAR_RESULT, 1
	goto_if_eq Ball_Room_EventScript_Birch_7
	compare VAR_RESULT, 2
	goto_if_eq Ball_Room_EventScript_Birch_8
	compare VAR_RESULT, 3
	goto_if_eq Ball_Room_EventScript_Birch_9
	compare VAR_RESULT, 4
	goto_if_eq Ball_Room_EventScript_Birch_10
	compare VAR_RESULT, 5
	goto_if_eq Ball_Room_EventScript_Birch_11
	compare VAR_RESULT, 6
	goto_if_eq Ball_Room_EventScript_Birch_12
	compare VAR_RESULT, 7
	goto_if_eq Ball_Room_EventScript_Birch_13
Ball_Room_EventScript_Birch_5:
	msgbox Ball_Room_EventScript_Birch_Text_1
	waitmessage
	release
	goto Ball_Room_EventScript_Birch_1

Ball_Room_EventScript_Birch_6:
	call StarterFade
	setvar STARTER_REGION, 0
	goto Ball_Room_EventScript_Birch_5

Ball_Room_EventScript_Birch_7:
	call StarterFade
	setvar STARTER_REGION, 1
	goto Ball_Room_EventScript_Birch_5

Ball_Room_EventScript_Birch_8:
	call StarterFade
	setvar STARTER_REGION, 2
	goto Ball_Room_EventScript_Birch_5

Ball_Room_EventScript_Birch_9:
	call StarterFade
	setvar STARTER_REGION, 3
	goto Ball_Room_EventScript_Birch_5

Ball_Room_EventScript_Birch_10:
	call StarterFade
	setvar STARTER_REGION, 4
	goto Ball_Room_EventScript_Birch_5

Ball_Room_EventScript_Birch_11:
	call StarterFade
	setvar STARTER_REGION, 5
	goto Ball_Room_EventScript_Birch_5

Ball_Room_EventScript_Birch_12:
	call StarterFade
	setvar STARTER_REGION, 6
	goto Ball_Room_EventScript_Birch_5

Ball_Room_EventScript_Birch_13:
	call StarterFade
	setvar STARTER_REGION, 7
	goto Ball_Room_EventScript_Birch_5


Ball_Room_EventScript_Ball1::
	lockall
	setvar VAR_TEMP_0, 5
	goto_if_unset FLAG_SYS_POKEMON_GET, Ball_Room_EventScript_Ball1_1
	msgbox Ball_Room_EventScript_Ball1_Text_0
	return

Ball_Room_EventScript_Ball1_1:
	compare STARTER_REGION, 0
	goto_if_eq Ball_Room_EventScript_Ball1_4
	compare STARTER_REGION, 1
	goto_if_eq Ball_Room_EventScript_Ball1_5
	compare STARTER_REGION, 2
	goto_if_eq Ball_Room_EventScript_Ball1_6
	compare STARTER_REGION, 3
	goto_if_eq Ball_Room_EventScript_Ball1_7
	compare STARTER_REGION, 4
	goto_if_eq Ball_Room_EventScript_Ball1_8
	compare STARTER_REGION, 5
	goto_if_eq Ball_Room_EventScript_Ball1_9
	compare STARTER_REGION, 6
	goto_if_eq Ball_Room_EventScript_Ball1_10
	compare STARTER_REGION, 7
	goto_if_eq Ball_Room_EventScript_Ball1_11
	return

Ball_Room_EventScript_Ball1_4:
	bufferspeciesname STR_VAR_1, SPECIES_SQUIRTLE
	setvar STARTER_CHOICE, SPECIES_SQUIRTLE
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball1_5:
	bufferspeciesname STR_VAR_1, SPECIES_TOTODILE
	setvar STARTER_CHOICE, SPECIES_TOTODILE
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball1_6:
	bufferspeciesname STR_VAR_1, SPECIES_MUDKIP
	setvar STARTER_CHOICE, SPECIES_MUDKIP
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball1_7:
	bufferspeciesname STR_VAR_1, SPECIES_PIPLUP
	setvar STARTER_CHOICE, SPECIES_PIPLUP
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball1_8:
	bufferspeciesname STR_VAR_1, SPECIES_OSHAWOTT
	setvar STARTER_CHOICE, SPECIES_OSHAWOTT
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball1_9:
	bufferspeciesname STR_VAR_1, SPECIES_FROAKIE
	setvar STARTER_CHOICE, SPECIES_FROAKIE
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball1_10:
	bufferspeciesname STR_VAR_1, SPECIES_POPPLIO
	setvar STARTER_CHOICE, SPECIES_POPPLIO
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball1_11:
	bufferspeciesname STR_VAR_1, SPECIES_SOBBLE
	setvar STARTER_CHOICE, SPECIES_SOBBLE
	call Ball_Room_EventScript_GiveStarter
	return


StarterFade::
	fadescreen FADE_TO_BLACK
	delay 20
	fadescreen FADE_FROM_BLACK
	return


Ball_Room_EventScript_Ball2::
	lockall
	setvar VAR_TEMP_0, 3
	goto_if_unset FLAG_SYS_POKEMON_GET, Ball_Room_EventScript_Ball2_1
	msgbox Ball_Room_EventScript_Ball1_Text_0
	return

Ball_Room_EventScript_Ball2_1:
	compare STARTER_REGION, 0
	goto_if_eq Ball_Room_EventScript_Ball2_4
	compare STARTER_REGION, 1
	goto_if_eq Ball_Room_EventScript_Ball2_5
	compare STARTER_REGION, 2
	goto_if_eq Ball_Room_EventScript_Ball2_6
	compare STARTER_REGION, 3
	goto_if_eq Ball_Room_EventScript_Ball2_7
	compare STARTER_REGION, 4
	goto_if_eq Ball_Room_EventScript_Ball2_8
	compare STARTER_REGION, 5
	goto_if_eq Ball_Room_EventScript_Ball2_9
	compare STARTER_REGION, 6
	goto_if_eq Ball_Room_EventScript_Ball2_10
	compare STARTER_REGION, 7
	goto_if_eq Ball_Room_EventScript_Ball2_11
	return

Ball_Room_EventScript_Ball2_4:
	bufferspeciesname STR_VAR_1, SPECIES_BULBASAUR
	setvar STARTER_CHOICE, SPECIES_BULBASAUR
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball2_5:
	bufferspeciesname STR_VAR_1, SPECIES_CHIKORITA
	setvar STARTER_CHOICE, SPECIES_CHIKORITA
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball2_6:
	bufferspeciesname STR_VAR_1, SPECIES_TREECKO
	setvar STARTER_CHOICE, SPECIES_TREECKO
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball2_7:
	bufferspeciesname STR_VAR_1, SPECIES_TURTWIG
	setvar STARTER_CHOICE, SPECIES_TURTWIG
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball2_8:
	bufferspeciesname STR_VAR_1, SPECIES_SNIVY
	setvar STARTER_CHOICE, SPECIES_SNIVY
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball2_9:
	bufferspeciesname STR_VAR_1, SPECIES_CHESPIN
	setvar STARTER_CHOICE, SPECIES_CHESPIN
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball2_10:
	bufferspeciesname STR_VAR_1, SPECIES_ROWLET
	setvar STARTER_CHOICE, SPECIES_ROWLET
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball2_11:
	bufferspeciesname STR_VAR_1, SPECIES_GROOKEY
	setvar STARTER_CHOICE, SPECIES_GROOKEY
	call Ball_Room_EventScript_GiveStarter
	return


Ball_Room_EventScript_Ball3::
	lockall
	setvar VAR_TEMP_0, 2
	goto_if_unset FLAG_SYS_POKEMON_GET, Ball_Room_EventScript_Ball3_1
	msgbox Ball_Room_EventScript_Ball1_Text_0
	return

Ball_Room_EventScript_Ball3_1:
	compare STARTER_REGION, 0
	goto_if_eq Ball_Room_EventScript_Ball3_4
	compare STARTER_REGION, 1
	goto_if_eq Ball_Room_EventScript_Ball3_5
	compare STARTER_REGION, 2
	goto_if_eq Ball_Room_EventScript_Ball3_6
	compare STARTER_REGION, 3
	goto_if_eq Ball_Room_EventScript_Ball3_7
	compare STARTER_REGION, 4
	goto_if_eq Ball_Room_EventScript_Ball3_8
	compare STARTER_REGION, 5
	goto_if_eq Ball_Room_EventScript_Ball3_9
	compare STARTER_REGION, 6
	goto_if_eq Ball_Room_EventScript_Ball3_10
	compare STARTER_REGION, 7
	goto_if_eq Ball_Room_EventScript_Ball3_11
	return

Ball_Room_EventScript_Ball3_4:
	bufferspeciesname STR_VAR_1, SPECIES_CHARMANDER
	setvar STARTER_CHOICE, SPECIES_CHARMANDER
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball3_5:
	bufferspeciesname STR_VAR_1, SPECIES_CYNDAQUIL
	setvar STARTER_CHOICE, SPECIES_CYNDAQUIL
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball3_6:
	bufferspeciesname STR_VAR_1, SPECIES_TORCHIC
	setvar STARTER_CHOICE, SPECIES_TORCHIC
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball3_7:
	bufferspeciesname STR_VAR_1, SPECIES_CHIMCHAR
	setvar STARTER_CHOICE, SPECIES_CHIMCHAR
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball3_8:
	bufferspeciesname STR_VAR_1, SPECIES_TEPIG
	setvar STARTER_CHOICE, SPECIES_TEPIG
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball3_9:
	bufferspeciesname STR_VAR_1, SPECIES_FENNEKIN
	setvar STARTER_CHOICE, SPECIES_FENNEKIN
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball3_10:
	bufferspeciesname STR_VAR_1, SPECIES_LITTEN
	setvar STARTER_CHOICE, SPECIES_LITTEN
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball3_11:
	bufferspeciesname STR_VAR_1, SPECIES_SCORBUNNY
	setvar STARTER_CHOICE, SPECIES_SCORBUNNY
	call Ball_Room_EventScript_GiveStarter
	return


Ball_Room_EventScript_Ball4::
	lockall
	setvar VAR_TEMP_0, 4
	goto_if_unset FLAG_SYS_POKEMON_GET, Ball_Room_EventScript_Ball4_1
	msgbox Ball_Room_EventScript_Ball1_Text_0
	return

Ball_Room_EventScript_Ball4_1:
	compare STARTER_REGION, 0
	goto_if_eq Ball_Room_EventScript_Ball4_4
	compare STARTER_REGION, 1
	goto_if_eq Ball_Room_EventScript_Ball4_5
	compare STARTER_REGION, 2
	goto_if_eq Ball_Room_EventScript_Ball4_6
	compare STARTER_REGION, 3
	goto_if_eq Ball_Room_EventScript_Ball4_7
	compare STARTER_REGION, 4
	goto_if_eq Ball_Room_EventScript_Ball4_8
	compare STARTER_REGION, 5
	goto_if_eq Ball_Room_EventScript_Ball4_9
	compare STARTER_REGION, 6
	goto_if_eq Ball_Room_EventScript_Ball4_10
	compare STARTER_REGION, 7
	goto_if_eq Ball_Room_EventScript_Ball4_11
	return

Ball_Room_EventScript_Ball4_4:
	bufferspeciesname STR_VAR_1, SPECIES_MEWTWO
	setvar STARTER_CHOICE, SPECIES_MEWTWO
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball4_5:
	bufferspeciesname STR_VAR_1, SPECIES_SUICUNE
	setvar STARTER_CHOICE, SPECIES_SUICUNE
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball4_6:
	bufferspeciesname STR_VAR_1, SPECIES_JIRACHI
	setvar STARTER_CHOICE, SPECIES_JIRACHI
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball4_7:
	bufferspeciesname STR_VAR_1, SPECIES_SHAYMIN
	setvar STARTER_CHOICE, SPECIES_SHAYMIN
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball4_8:
	bufferspeciesname STR_VAR_1, SPECIES_VICTINI
	setvar STARTER_CHOICE, SPECIES_VICTINI
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball4_9:
	bufferspeciesname STR_VAR_1, SPECIES_DIANCIE
	setvar STARTER_CHOICE, SPECIES_DIANCIE
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball4_10:
	bufferspeciesname STR_VAR_1, SPECIES_NECROZMA
	setvar STARTER_CHOICE, SPECIES_NECROZMA
	call Ball_Room_EventScript_GiveStarter
	return

Ball_Room_EventScript_Ball4_11:
	bufferspeciesname STR_VAR_1, SPECIES_CALYREX
	setvar STARTER_CHOICE, SPECIES_CALYREX
	call Ball_Room_EventScript_GiveStarter
	return


Ball_Room_EventScript_GiveStarter::
	showmonpic STARTER_CHOICE, 10, 3
	msgbox Ball_Room_EventScript_GiveStarter_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Ball_Room_EventScript_GiveStarter_1
	hidemonpic
	msgbox Ball_Room_NotChosen
	closemessage
	return

Ball_Room_EventScript_GiveStarter_1:
	setflag FLAG_SYS_POKEMON_GET
	setvar LITTLEROOT_STATE, 2
	givemon STARTER_CHOICE, 5, ITEM_NONE
	compare VAR_RESULT, MON_GIVEN_TO_PARTY
	goto_if_eq Ball_Room_EventScript_GiveStarter_5
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq Ball_Room_EventScript_GiveStarter_6
	hidemonpic
	msgbox Ball_Room_EventScript_GiveStarter_Text_3
	closemessage
Ball_Room_EventScript_GiveStarter_4:
	closemessage
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	call InitiatePokedexSequenceandRivalBattle
	return

Ball_Room_EventScript_GiveStarter_5:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Ball_Room_EventScript_GiveStarter_Text_1
	removeobject VAR_TEMP_0
	call SetBallFlag
	call NicknamePartyMon
	goto Ball_Room_EventScript_GiveStarter_4

Ball_Room_EventScript_GiveStarter_6:
	playfanfare MUS_OBTAIN_ITEM
	msgbox Ball_Room_EventScript_GiveStarter_Text_1
	removeobject VAR_TEMP_0
	call SetBallFlag
	call NicknameBoxMon
	msgbox Ball_Room_EventScript_GiveStarter_Text_2
	goto Ball_Room_EventScript_GiveStarter_4


InitiatePokedexSequenceandRivalBattle::
	lock
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, TurnToProfRight
	compare VAR_TEMP_0, 5
	goto_if_eq InitiatePokedexSequenceandRivalBattle_2
InitiatePokedexSequenceandRivalBattle_1:
	compare VAR_TEMP_0, 3
	goto_if_eq InitiatePokedexSequenceandRivalBattle_5
InitiatePokedexSequenceandRivalBattle_4:
	compare VAR_TEMP_0, 2
	goto_if_eq InitiatePokedexSequenceandRivalBattle_8
InitiatePokedexSequenceandRivalBattle_7:
	compare VAR_TEMP_0, 4
	goto_if_eq InitiatePokedexSequenceandRivalBattle_11
InitiatePokedexSequenceandRivalBattle_10:
	waitmovement 0
	delay 20
	call GivePokedex
	addobject 6
	setobjectxy 6, 6, 7
	call RivalBattleTrigger
	release
	return

InitiatePokedexSequenceandRivalBattle_2:
	setvar VAR_STARTER_MON, 2
	applymovement 1, MoveBall1
	goto InitiatePokedexSequenceandRivalBattle_1

InitiatePokedexSequenceandRivalBattle_5:
	setvar VAR_STARTER_MON, 0
	applymovement 1, MoveBall2
	goto InitiatePokedexSequenceandRivalBattle_4

InitiatePokedexSequenceandRivalBattle_8:
	setvar VAR_STARTER_MON, 1
	applymovement 1, MoveBall3
	goto InitiatePokedexSequenceandRivalBattle_7

InitiatePokedexSequenceandRivalBattle_11:
	setvar VAR_STARTER_MON, 0
	applymovement 1, MoveBall4
	goto InitiatePokedexSequenceandRivalBattle_10


GivePokedex::
	lock
	msgbox TakePokedex, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	closemessage
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_ADVENTURE_STARTED
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	call UpgradeNationalDex
	msgbox GivePokedex_Text_0, MSGBOX_DEFAULT
	giveitem ITEM_POKE_BALL, 5
	msgbox GivePokedex_Text_1, MSGBOX_DEFAULT
	waitmessage
	release
	return


UpgradeNationalDex::
	lock
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_PokedexUpgradedToNational
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	closemessage
	release
	return


TurnToProfRight:
	face_right
	step_end

TurnToProfLeft:
	face_left
	step_end

MoveBall1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_player
	step_end

MoveBall2:
	walk_left
	walk_up
	face_player
	step_end

MoveBall3:
	walk_right
	walk_right
	walk_up
	face_player
	step_end

MoveBall4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	face_player
	step_end

Water:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

Grass:
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

Fire:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

Legendaries:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

RivalBattleTrigger::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, MayBattle
	goto_if_eq VAR_RESULT, FEMALE, BrendanBattle
	return


MayBattle::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	compare VAR_TEMP_0, 5
	goto_if_eq MayBattle_2
MayBattle_1:
	compare VAR_TEMP_0, 3
	goto_if_eq MayBattle_5
MayBattle_4:
	compare VAR_TEMP_0, 2
	goto_if_eq MayBattle_8
MayBattle_7:
	compare VAR_TEMP_0, 4
	goto_if_eq MayBattle_11
MayBattle_10:
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, RivalMoveUp
	waitmovement 0
	compare VAR_TEMP_0, 5
	goto_if_eq MayBattle_14
MayBattle_13:
	compare VAR_TEMP_0, 3
	goto_if_eq MayBattle_17
MayBattle_16:
	compare VAR_TEMP_0, 2
	goto_if_eq MayBattle_20
MayBattle_19:
	compare VAR_TEMP_0, 4
	goto_if_eq MayBattle_23
MayBattle_22:
	end

MayBattle_2:
	applymovement 6, Water
	goto MayBattle_1

MayBattle_5:
	applymovement 6, Grass
	goto MayBattle_4

MayBattle_8:
	applymovement 6, Fire
	goto MayBattle_7

MayBattle_11:
	applymovement 6, Legendaries
	goto MayBattle_10

MayBattle_14:
	trainerbattle_single TRAINER_MAY_ROUTE_103_MUDKIP, May_Intro, Route103_Text_MayDefeated, RivalBattleOver
	goto MayBattle_13

MayBattle_17:
	trainerbattle_single TRAINER_MAY_ROUTE_103_TREECKO, May_Intro, Route103_Text_MayDefeated, RivalBattleOver
	goto MayBattle_16

MayBattle_20:
	trainerbattle_single TRAINER_MAY_ROUTE_103_TORCHIC, May_Intro, Route103_Text_MayDefeated, RivalBattleOver
	goto MayBattle_19

MayBattle_23:
	trainerbattle_single TRAINER_MAY_ROUTE_103_TREECKO, May_Intro, Route103_Text_MayDefeated, RivalBattleOver
	goto MayBattle_22


BrendanBattle::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	compare VAR_TEMP_0, 5
	goto_if_eq BrendanBattle_2
BrendanBattle_1:
	compare VAR_TEMP_0, 3
	goto_if_eq BrendanBattle_5
BrendanBattle_4:
	compare VAR_TEMP_0, 2
	goto_if_eq BrendanBattle_8
BrendanBattle_7:
	compare VAR_TEMP_0, 4
	goto_if_eq BrendanBattle_11
BrendanBattle_10:
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 6, RivalMoveUp
	waitmovement 0
	compare VAR_TEMP_0, 5
	goto_if_eq BrendanBattle_14
BrendanBattle_13:
	compare VAR_TEMP_0, 3
	goto_if_eq BrendanBattle_17
BrendanBattle_16:
	compare VAR_TEMP_0, 2
	goto_if_eq BrendanBattle_20
BrendanBattle_19:
	compare VAR_TEMP_0, 4
	goto_if_eq BrendanBattle_23
BrendanBattle_22:
	end

BrendanBattle_2:
	applymovement 6, Water
	goto BrendanBattle_1

BrendanBattle_5:
	applymovement 6, Grass
	goto BrendanBattle_4

BrendanBattle_8:
	applymovement 6, Fire
	goto BrendanBattle_7

BrendanBattle_11:
	applymovement 6, Legendaries
	goto BrendanBattle_10

BrendanBattle_14:
	trainerbattle_single TRAINER_BRENDAN_ROUTE_103_MUDKIP, May_Intro, Route103_Text_BrendanDefeated, RivalBattleOver
	goto BrendanBattle_13

BrendanBattle_17:
	trainerbattle_single TRAINER_BRENDAN_ROUTE_103_TREECKO, May_Intro, Route103_Text_BrendanDefeated, RivalBattleOver
	goto BrendanBattle_16

BrendanBattle_20:
	trainerbattle_single TRAINER_BRENDAN_ROUTE_103_TORCHIC, May_Intro, Route103_Text_BrendanDefeated, RivalBattleOver
	goto BrendanBattle_19

BrendanBattle_23:
	trainerbattle_single TRAINER_BRENDAN_ROUTE_103_TORCHIC, May_Intro, Route103_Text_BrendanDefeated, RivalBattleOver
	goto BrendanBattle_22


RivalBattleOver::
	lockall
	msgbox BattleEnd
	compare VAR_TEMP_0, 5
	goto_if_eq RivalBattleOver_2
RivalBattleOver_1:
	compare VAR_TEMP_0, 3
	goto_if_eq RivalBattleOver_5
RivalBattleOver_4:
	compare VAR_TEMP_0, 2
	goto_if_eq RivalBattleOver_8
RivalBattleOver_7:
	compare VAR_TEMP_0, 4
	goto_if_eq RivalBattleOver_11
RivalBattleOver_10:
	waitmovement 0
	setflag Rival_Battle_Start
	setvar LITTLEROOT_STATE, 3
	removeobject 6
	releaseall
	return

RivalBattleOver_2:
	applymovement 6, LeaveWater
	goto RivalBattleOver_1

RivalBattleOver_5:
	applymovement 6, LeaveGrass
	goto RivalBattleOver_4

RivalBattleOver_8:
	applymovement 6, LeaveFire
	goto RivalBattleOver_7

RivalBattleOver_11:
	applymovement 6, LeaveLegendaries
	goto RivalBattleOver_10


RivalMoveUp:
	walk_up
	step_end

LeaveWater:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LeaveGrass:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LeaveFire:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LeaveLegendaries:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SetBallFlag::
	compare VAR_TEMP_0, 5
	goto_if_eq SetBallFlag_2
	compare VAR_TEMP_0, 3
	goto_if_eq SetBallFlag_5
	compare VAR_TEMP_0, 2
	goto_if_eq SetBallFlag_8
	compare VAR_TEMP_0, 4
	goto_if_eq SetBallFlag_10
	return

SetBallFlag_2:
	setflag Starter_Ball1
	return

SetBallFlag_5:
	setflag Starter_Ball2
	return

SetBallFlag_8:
	setflag Starter_Ball3
	return

SetBallFlag_10:
	setflag Starter_Ball4
	return


NicknamePartyMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_1
	return

NicknamePartyMon_1:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return


NicknameBoxMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknameBoxMon_2
NicknameBoxMon_1:
	msgbox NicknameBoxMon_Text_0
	return

NicknameBoxMon_2:
	call Common_EventScript_NameReceivedBoxMon
	goto NicknameBoxMon_1


StopLeaving_Text_0:
	.string "You Need To Choose a Pokemon.$"

Ball_Room_EventScript_Birch_Text_0:
	.string "Would you like to see more?$"

Ball_Room_EventScript_Birch_Text_1:
	.string "Choose wisely...$"

Ball_Room_EventScript_Birch_Text_2:
	.string "Take care of your Pokemon$"

Ball_Room_EventScript_Ball1_Text_0:
	.string "Don't Take Another$"

Ball_Room_EventScript_GiveStarter_Text_0:
	.string "Do you want to choose {STR_VAR_1}?$"

Ball_Room_EventScript_GiveStarter_Text_1:
	.string "Recieved {STR_VAR_1}$"

Ball_Room_EventScript_GiveStarter_Text_2:
	.string "Transferred {STR_VAR_1} to PC$"

Ball_Room_EventScript_GiveStarter_Text_3:
	.string "No More Room For Pokemon$"

GivePokedex_Text_0:
	.string "Also take these with you$"

GivePokedex_Text_1:
	.string "These allow you to catch your own\n"
	.string "Pokemon in tall grass so you can\l"
	.string "collect research for the Pokedex$"

NicknamePartyMon_Text_0:
	.string "Give a nickname?$"

NicknameBoxMon_Text_0:
	.string "Transferred to PC$"

TakePokedex::
	.string "Here, {PLAYER}, I ordered this for my\n"
	.string "research, but I think you should have\l"
	.string "this PokeDex.$"

BattleEnd::
	.string "Well that wasn't fun.\n"
	.string "I'll beat you next time.$"

MayIntro::
	.string "We'll See if you have what it takes!$"

Ball_Room_NotChosen::
	.string "You did not choose {STR_VAR_1}.$"

BeginAdventureText::
	.string "{COLOR GREEN}{SHADOW LIGHT_GREEN}Birch:{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} {PLAYER}, here's where it all begins.\p"
	.string "{PLAYER} select a Pokemon, \n"
	.string "or ask to change region. \p"
	.string "Also, don't forget the Pokedex!\n"
	.string "It's a device to keep track of Pokemon.\p"
	.string "Be careful, and try to {COLOR LIGHT_RED}{SHADOW RED}Catch 'Em All{COLOR DARK_GRAY}!$"

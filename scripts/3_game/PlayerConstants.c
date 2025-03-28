modded class PlayerConstants
{
	//----------------------------------------------------------
	//						AI SENSOR MULTIPLIER
	//----------------------------------------------------------
	static const float AI_NOISE_ROLL = 0.5;//2;				//Multiplier for the noise generated while prone rolling
	static const float AI_NOISE_SPRINT = 1;				//Multiplier for the noise generated while sprinting
	static const float AI_NOISE_RUN = 0.8;				//Multiplier for the noise generated while jogging
	static const float AI_NOISE_CROUCH_RUN = 0.3;//0.6;				//Multiplier for the noise generated while Sprint crouch
	static const float AI_NOISE_WALK = 0.4;				//Multiplier for the noise generated while walking
	static const float AI_NOISE_IDLE = 0;				//Multiplier for the noise generated while staying still
	static const float AI_NOISE_SHOES_BOOTS = 0.75; //0.85;				//Multiplier for the noise generated while wearing boots
	static const float AI_NOISE_SHOES_SNEAKERS = 0.5; //0.6;				//Multiplier for the noise generated while wearing sneakers
	static const float AI_NOISE_SHOES_NONE = 0.25; //0.45;				//Multiplier for the noise generated while not wearing shoes
	static const float AI_VISIBILITY_RUN = 1.5;//1;				//Multiplier for the visibility of the player while jogging or sprinting
	static const float AI_VISIBILITY_WALK = 0.5; //0.66;				//Multiplier for the visibility of the player while walking
	static const float AI_VISIBILITY_IDLE = 0.3;				//Multiplier for the visibility of the player while staying still
	static const float AI_VISIBILITY_STANDING = 1;//1.5;				//Multiplier for the visibility of the player while standing
	static const float AI_VISIBILITY_CROUCH = 0.3; //0.6;				//Multiplier for the visibility of the player while crouched
	static const float AI_VISIBILITY_PRONE = 0.05;//0.15;				//Multiplier for the visibility of the player while prone
}
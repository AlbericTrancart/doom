#include "headers/sound.h"

//Fichiers sons
const char* MUSIC = {"sound/music.wav"};

//Son des armes
const char* WEAPONSRC[] = {
    "sound/w_kick.wav",
    "sound/w_fist.wav",
    "sound/w_gun.wav",
    "sound/w_shotgun.wav",
    "sound/w_carbine.wav",
    "sound/w_machinegun.wav",
    "sound/w_plasmagun.wav",
    "sound/w_reload.wav",
};
const int nbWeapons = 8;

//Son des poulets
const char* CHICKENSRC[] = {
    "sound/c_idle.wav",
    "sound/c_kick.wav",
};
const int nbChicken = 2;

//DUKE NUKEM POWAAAAA !
const char* PUNCHLINESRC[] = {
    "sound/p_back_2_work_y.wav",
    "sound/p_birth_control.wav",
    "sound/p_biggers_than_yours.wav",
    "sound/p_come_get_some_x.wav",
    "sound/p_hail.wav",
    "sound/p_kick_ass.wav",
    "sound/p_make_day.wav",
    "sound/p_only_one.wav",
    "sound/p_ugly.wav",
    "sound/p_whats_the_difference.wav",
};
const int nbPunchline = 10;

//Son quand le perso est blessé
const char* HURTSRC[] = {
    "sound/h_annoying.wav",
    "sound/h_gotta_hurt.wav",
    "sound/h_holy_sh.wav",
    "sound/h_bitch.wav",
    "sound/h_shit_happens.wav",
    "sound/h_you_will_die.wav",
};
const int nbHurt = 6;

//Phrase de début
const char* STARTSRC[] = {
    "sound/s_balls.wav",
    "sound/s_equal_opportunity.wav",
    "sound/s_lets_rock.wav",
    "sound/s_gum.wav",
    "sound/s_duke.wav",
    "sound/s_rotten.wav",
};
const int nbStart = 6;

//Son à la mort de méchants
const char* DIESSRC[] = {
    "sound/d_blow_it_x.wav",
    "sound/d_cya_n_hell.wav",
    "sound/d_good.wav",
    "sound/d_hello.wav",
    "sound/d_rip.wav",//
    "sound/d_terminated.wav",//
    "sound/d_yippie_kaiay.wav",//
};
const int nbDies = 7;

Mix_Music *music;
Mix_Chunk *gameover;
Mix_Chunk* weapon[nbWeapons];
Mix_Chunk* chicken[nbChicken];
Mix_Chunk* punchline[nbPunchline];
Mix_Chunk* hurt[nbHurt];
Mix_Chunk* start[nbStart];
Mix_Chunk* dies[nbDies];

//Sert à charger les sons depuis le tableau des noms
void sLoadAudio(Mix_Chunk* sounds[], const char* names[], const int nbSounds){
    for(int i = 0; i < nbSounds; ++i){
        sounds[i] = Mix_LoadWAV(names[i]);
    }
}

//Libère la mémoire
void sFreeAudio(Mix_Chunk* sounds[], const int nbSounds){
    for(int i = 0; i < nbSounds; ++i){
        Mix_FreeChunk(sounds[i]);
    }
}

//Démarrage du module audio, chargement des sons et mise en boucle de la musique
void sInitAudio(){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    
    //Par défaut on prend 4 canaux
    //1: joueur
    //2: armes
    //3: poulets
    //4: libre
    Mix_AllocateChannels(4);
    
    music = Mix_LoadMUS(MUSIC);
    Mix_PlayMusic(music, -1);
    
    gameover = Mix_LoadWAV("sound/game_over.wav");
    sLoadAudio(weapon, WEAPONSRC, nbWeapons);
    sLoadAudio(chicken, CHICKENSRC, nbChicken);
    sLoadAudio(punchline, PUNCHLINESRC, nbPunchline);
    sLoadAudio(hurt, HURTSRC, nbHurt);
    sLoadAudio(start, STARTSRC, nbStart);
    sLoadAudio(dies, DIESSRC, nbDies);
    
    //sStart();
    Mix_Chunk *test;
    test = Mix_LoadWAV("sound/s_gum.wav");
    Mix_PlayChannel(1, test, 0);
}

//On ferme le module audio
void sEndAudio(){
    Mix_PlayChannel(-1, gameover, 0);
    milliSleep(2000);
    Mix_FreeChunk(gameover);
    
    sFreeAudio(weapon, nbWeapons);
    sFreeAudio(chicken, nbChicken);
    sFreeAudio(punchline, nbPunchline);
    sFreeAudio(hurt, nbHurt);
    sFreeAudio(start, nbStart);
    sFreeAudio(dies, nbDies);
    Mix_FreeMusic(music);
    
    Mix_CloseAudio();
}

//Joue un son random si le poulet n'est pas kické, sinon son de kick
void sChicken(bool kick){
    if(!kick)
        Mix_PlayChannel(1, chicken[0], 0);
    else
        Mix_PlayChannel(1, chicken[1], 0);
}

//Joue un son correspondant à l'arme voulue
void sWeapon(int weaponid){
    Mix_PlayChannel(2, weapon[weaponid], 0);
}

//Chacune de ces fonctions joue de façon aléatoire un son dans les tables audio correspondantes
void sPunchline(){
    int id = uRandom(0, nbPunchline-1);
    Mix_PlayChannel(1, punchline[id], 0);
}

void sHurt(){
    int id = uRandom(0, nbHurt-1);
    Mix_PlayChannel(1, hurt[id], 0);
}

void sStart(){
    int id = uRandom(0, nbStart-1);
    Mix_PlayChannel(1, start[id], 0);
}

void sDies(){
    int id = uRandom(0, nbDies-1);
    Mix_PlayChannel(1, dies[id], 0);
}
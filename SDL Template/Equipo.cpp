#include "Equipo.h"
void Equipo::CleanSolt(item* slot) {
    if (slot != NULL)
    {
        delete slot;
    }
    slot = NULL;
}
int Equipo::GetBlockKey() {
    return MblockKey;
};
void Equipo::SetBlockKey(int BlockStatus) {
    MblockKey = BlockStatus;
};

void Equipo::RenderItem(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, MEquipo.texture, NULL, &MEquipo.rect);
    if (slot1 != NULL) {

        slot1->setItemImgRect(250, 170);
        slot1->render(renderer);
    }
    if (slot2 != NULL) {
            
        slot2->setItemImgRect(250, 280);
        slot2->render(renderer);
    }
    if (slot3 != NULL) {

        slot3->setItemImgRect(250, 390);
        slot3->render(renderer);
    }
    if(MblockKey != 0)
        SDL_RenderCopy(renderer, MMensaje.texture, NULL, &MMensaje.rect);
};

void Equipo::InitImage(SDL_Renderer* renderer) {
    Img::LoadImage("assets/equip.png", MEquipo);
    MEquipo.rect.x = 50;
    MEquipo.rect.y = 20;
    Img::LoadImage("assets/mensaje.png", MMensaje);
    MMensaje.rect.x = 800;
    MMensaje.rect.y = 350;
};
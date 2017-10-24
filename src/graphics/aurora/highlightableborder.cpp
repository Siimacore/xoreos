//
// Created by Siimacore on 24/10/17.
//

#include "src/graphics/aurora/textureman.h"
#include "highlightableborder.h"

namespace Graphics {

namespace Aurora {

HighlightableBorder::HighlightableBorder(const Common::UString &edge, const Common::UString &corner, float x,
                                         float y, float w, float h,
                                         const Common::UString &cornerH, const Common::UString &edgeH): BorderQuad(edge, corner, x, y, w, h)
{
    _edge = TextureMan.get(edge);
    _edgeH = TextureMan.get(edgeH);
    _corner = TextureMan.get(corner);
    _cornerH = TextureMan.get(cornerH);

}

HighlightableBorder::~HighlightableBorder() {}

void HighlightableBorder::render(RenderPass pass) {
    if(isHighlightable() && isHightlighted()){
        setCornerTexture(_cornerH);
        setEdgeTexture(_edgeH);
    } else {
        setCornerTexture(_corner);
        setEdgeTexture(_edge);
    }
    Graphics::Aurora::BorderQuad::render(pass);
}

void HighlightableBorder::setHighlightCornerTexture(const TextureHandle &corner) {
    _cornerH = corner;
}

void HighlightableBorder::setHighlightEdgeTexture(const TextureHandle &edge) {
    _edgeH = edge;
}

}

}
